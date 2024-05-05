import os

markdown_file_initial_directory = '/Users/hqc/Downloads/'
target_root_directory = '/Users/hqc/Documents/projects/cpp/algorithm/algorithm/oj/atcoder/'


def trim(path):
    lines = open(path, 'r').readlines()
    content = lines[0] + lines[3] + lines[5]
    for i in range(35, len(lines)):
        if lines[i] == 'Copy\n':
            i += 1
            continue
        elif lines[i][-5:] == "Copy\n":
            content += lines[i][:-5]
        elif lines[i] == '\n' and lines[i + 3] == "Language\n":
            break
        else:
            content += lines[i]
    with open(path, 'w') as f:
        f.write(content)


def move(filename):
    file_path = markdown_file_initial_directory + filename
    lines = open(file_path, 'r').readlines()
    link_line = lines[3]
    contest_id = link_line[link_line.rfind('/') + 1:link_line.rfind('_')]
    problem_id = link_line[link_line.rfind('_') + 1:-1].upper()
    target_directory = target_root_directory + contest_id + '/' + problem_id + '/'
    os.system('mkdir -p %s' % target_directory)
    os.system('mv "%s" "%s"' % (file_path, target_directory))
    trim(target_directory + filename)


if __name__ == '__main__':
    files = os.listdir(markdown_file_initial_directory)
    for file in files:
        if file[0].isupper() and file[1] == ' ' and file[-3:] == '.md':
            move(file)
