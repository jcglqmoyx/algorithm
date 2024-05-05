import os

md_file_init_directory = '/Users/hqc/Documents/obsidian'
source_code_root_directory = '/Users/hqc/Documents/projects/cpp/algorithm/algorithm'

files = os.listdir(md_file_init_directory)
md_file = ''
for file in files:
    if file[0].isnumeric() and file[-3:] == '.md':
        md_file = file
        break

problem_id = ''
for c in md_file:
    if c.isnumeric():
        problem_id += c
    else:
        break
problem_id = int(problem_id)

category_l = (problem_id - 1) // 100 * 100 + 1
category_r = category_l + 99

category = '%d-%d' % (category_l, category_r)

md_file_target_directory = '%s/oj/leetcode/%s/%s' % (source_code_root_directory, category, problem_id)

os.system('mkdir -p %s' % md_file_target_directory)
os.system("mv %s/'%s' %s" % (md_file_init_directory, md_file, md_file_target_directory))
