from typing import List

class Solution:
    def fullJustify(self, words: List[str], max_width: int) -> List[str]:
        i = 0
        n = len(words)
        line_index = 0
        lines = [[]]
        curr = 0
        while i < n:
            word_len = len(words[i])
            if curr + word_len + len(lines[-1]) <= max_width:
                lines[-1].append(words[i])
                curr += word_len
            else:
                lines[-1].append(max_width - curr)
                lines.append([])
                lines[-1].append(words[i])
                curr = word_len
            i += 1
        lines[-1].append(max_width - curr)
        out = []
        no_lines = len(lines)
        for line_index in range(no_lines):
            line = lines[line_index]
            spaces = line.pop()
            line_length = len(line)
            if line_length == 1:
                out.append(line[0] + ' ' * spaces)
                continue
            if line_index == no_lines - 1:
                out.append(' '.join(line) + ' ' * (spaces - (len(line) - 1)))
                continue
            spaces_each = spaces // (line_length - 1)
            extra_spaces = spaces % (line_length - 1)
            curr_line = ''
            for index, word in enumerate(line):
                if index == line_length - 1:
                    curr_line += word
                    continue
                curr_line += word
                curr_line += ' ' * spaces_each
                if extra_spaces != 0:
                    curr_line += ' '
                    extra_spaces -= 1
            out.append(curr_line)
        return out

print(Solution().fullJustify(["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], 20))
