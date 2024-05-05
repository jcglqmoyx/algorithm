import os

markdown_file_initial_directory = '/Users/hqc/Downloads/'
target_root_directory = '/Users/hqc/Documents/projects/cpp/algorithm/algorithm/oj/atcoder/'


def move(file):
    lines = open(file, 'r').readlines()
    link_line = lines[3]
    contest_id = link_line[link_line.rfind('/') + 1:link_line.rfind('_')]
    problem_id = link_line[link_line.rfind('_') + 1:-1].upper()
    target_directory = target_root_directory + contest_id + '/' + problem_id + '/'
    os.system('mkdir -p %s' % target_directory)
    os.system('mv "%s" "%s"' % (file, '/Users/hqc'))


files = os.listdir(markdown_file_initial_directory)
for file in files:
    if file[0].isupper() and file[1] == ' ' and file[-3:] == '.md':
        move(markdown_file_initial_directory + file)
