import functions as module

def main():
    ''' parse arguments '''
    arguments = module.argument_parser()
    ''' Get directories and / or files '''
    names = module.get_files_by_type(arguments)
    ''' Filter by search substring '''
    valid_names = module.get_files_by_search(names, arguments)
    ''' Get regexp for include and exclude strings '''
    regexp = module.get_regexp(arguments)
    ''' Get all valid files '''
    new_list = module.get_files(valid_names, regexp)

    ''' Print founded file's count '''
    print("Count of founded files is ", len(new_list))
    '''' Print first "count"-th files  '''
    if len(new_list):
        count = module.get_number(len(new_list))
        for i in range(count):
            print(i + 1, new_list[i])
    print()

if __name__ == "__main__":
    main()