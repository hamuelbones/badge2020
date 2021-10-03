
# Converts levels from a file, downloaded from here:
# https://github.com/begoon/sokoban-maps/blob/master/maps/sokoban-maps-60-plain.txt

import argparse
from bitstring import BitArray

def read_input_file(input_filename: str, limit: int):
    with open(input_filename, 'r') as input_file:

        levels = []
        line = ""
        try:
            for level_num in range(limit):
                # Simply match start of level
                while "***********" not in line:
                    line = input_file.readline()
                # Skip metadata...
                next(input_file)
                next(input_file)
                x_size = int(input_file.readline()[8:])
                y_size = int(input_file.readline()[8:])
                # Skip metadata...
                next(input_file)
                next(input_file)
                next(input_file)

                wall_data = BitArray()
                start = [0, 0]
                boxes = []
                goals = []

                for y in range(y_size):
                    line = input_file.readline()
                    for x, char in enumerate(line):
                        if char == 'X':
                            wall_data.append('0b1')
                            continue
                        else:
                            wall_data.append('0b0')

                        if char == '@':
                            start = [x, y]
                        elif char == '*':
                            boxes.append([x, y])
                        elif char == '.':
                            goals.append([x, y])

                    while len(wall_data) % 8 != 0:
                        wall_data.append('0b0')

                levels.append({
                    'x': x_size,
                    'y': y_size,
                    'goals': goals,
                    'boxes': boxes,
                    'start': start,
                    'map': wall_data,

                })
        except StopIteration:
            print("Reached end of data file")
            pass

        return levels


def write_output_file(output_filename: str, levels: list):

    with open(output_filename, "w") as out_file:
        out_file.write("// Generated level file by convert_levels.py\n\n")
        out_file.write("#include \"levels.h\"\n\n")

        for level_num, level in enumerate(levels):
            boxes = level["boxes"]
            goals = level["goals"]
            wall_data = level["map"]

            out_file.write(f"static const SOKOBAN_COORDS level_{level_num}_boxes[{len(boxes)}] = {{\n")
            for box_num, box in enumerate(boxes):
                out_file.write(f"    [{box_num}] = {{.x = {box[0]}, .y = {box[1]}}},\n")
            out_file.write("};\n\n")

            out_file.write(f"static const SOKOBAN_COORDS level_{level_num}_goals[{len(goals)}] = {{\n")
            for goal_num, goal in enumerate(goals):
                out_file.write(f"    [{goal_num}] = {{.x = {goal[0]}, .y = {goal[1]}}},\n")
            out_file.write("};\n\n")

            out_file.write(f"static const uint8_t level_{level_num}_map[{int(len(wall_data)/8)}] = {{\n    ")
            for i in range(0, len(wall_data), 8):
                num = int(i/8)
                b = wall_data[i:i+8].bin
                out_file.write(f"0b{b}, ")
                if (num + 1) % int((level["x"]+7)/8) == 0:
                    out_file.write("\n    ")
            out_file.write("};\n\n")

            out_file.write(f"static const SOKOBAN_LEVEL level_{level_num} = {{\n")
            out_file.write(f"    .level_size = {{.x = {level['x']}, .y = {level['y']}}},\n")
            out_file.write(f"    .player_start = {{.x = {level['start'][0]}, .y = {level['start'][1]}}},\n")
            out_file.write(f"    .num_boxes = {len(boxes)},\n")
            out_file.write(f"    .box_coords = level_{level_num}_boxes,\n")
            out_file.write(f"    .goal_coords = level_{level_num}_goals,\n")
            out_file.write(f"    .map = level_{level_num}_map,\n")
            out_file.write("};\n\n");

        out_file.write(f"static const SOKOBAN_LEVEL *levels[{len(levels)}] = {{\n")
        for i, _ in enumerate(levels):
            out_file.write(f"    [{i}] = &level_{i},\n")
        out_file.write("};\n\n")

        out_file.write("uint8_t soko_level_count(void) {\n")
        out_file.write(f"    return {len(levels)};\n")
        out_file.write("}\n\n")

        out_file.write("const SOKOBAN_LEVEL * soko_get_level(uint8_t num) {\n")
        out_file.write(f"    return levels[num];\n")
        out_file.write("}\n\n")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Sokoban C structure generator")
    parser.add_argument("input_file", help="Input Sokoban text data file")
    parser.add_argument("--output_file", "-o", default="output.c", help="Output Sokoban level C file")
    parser.add_argument("--limit", "-l", type=int, default=100, help="Maximum levels to parse")
    args = parser.parse_args()

    write_output_file(args.output_file, read_input_file(args.input_file, args.limit))



