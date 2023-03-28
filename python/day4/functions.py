import argparse
import os
import re


def get_files_by_type(arguments):
    is_file = arguments["file"]
    is_direct = arguments["directory"]
    path = arguments["path"]

    ''' Get all existing directories and files '''
    ''' If we need directories and files return all '''
    ''' If we need directories or files, return filtered '''
    names = list()
    for address, dirs, files in os.walk(path):
        if not files == [] and is_file:
            for i in files:
                names.append(address + "/" + i)
        if not dirs == [] and is_direct:
            for i in dirs:
                names.append(address + "/" + i)
    return names


def argument_parser():
    ''' Arguments description '''
    parser = argparse.ArgumentParser(description="File search in directory")
    parser.add_argument("--path", type = str, default = ".", help = "Path to file")
    parser.add_argument("--include", type = str, help = "Include only that kind of files")
    parser.add_argument("--exclude", type = str, help = "Do not find that kind of files")
    parser.add_argument("--search", type = str, required = True, help = "File name... required argument")
    parser.add_argument("-f", action = "store_true", dest = "file", default = False, help = "")
    parser.add_argument("-d", action = "store_true", dest = "directory", default = False, help = "")

    ''' Argument parse to list '''
    args = parser.parse_args()
    arguments = {}
    for key, value in vars(args).items():
        arguments[key] = value

    ''' If there is not key -d or -f, must be directories and files '''
    if arguments["directory"] == arguments["file"]:
            arguments["directory"] = True
            arguments["file"] = True

    return arguments


def get_files_by_search(names, arguments):
    ''' Get all files where exists search substring '''
    word = arguments["search"]
    new_names = list()

    if names:
        for name in names:
            if word in name:
                new_names.append(name)

    return new_names


def get_regexp(arguments):
    ''' Get regexp for include and exclude strings '''
    include = arguments["include"]
    exclude = arguments["exclude"]

    if include:
        include.replace("*", "(.*)")
        include.replace("?", "(.)")
        include = "{.*}/" + include

    if exclude:
        exclude.replace("*", "(.*)")
        exclude.replace("?", "(.)")
        exclude = "{.*}/" + exclude

    ''' Return list for include and exclude regexps '''
    return [include, exclude]


def get_files(names, regexp):
    ''' Get include and exclude regexp string '''
    include, exclude = regexp

    ''' If exist, compile th regexp '''
    reg_inc = None
    if include:
        reg_inc = re.compile(include)

    reg_exc = None
    if exclude:
        reg_exc = re.compile(exclude)

    ''' If can't find regexp, return names '''
    if not reg_exc and not reg_inc:
        return names

    ''' If include and exclude is equal, not any files '''
    if reg_exc == reg_inc:
        return []

    ''' Get files by include and remove by exclude'''
    new_list = list()
    for i in names:
        if reg_inc and reg_inc.match(i):
            new_list.append(i)

    for i in new_list:
        if reg_exc and reg_exc.match(i):
            new_list.remove(i)

    return new_list


def get_number(second):
    ''' Enter only integer number(not the other charecter) '''
    ''' Number must be in range [0, second]'''
    ''' If file count is equal to 0 '''
    if second < 1:
        print("There are not any files !!!")
        return

    print("Enter file count that you want to see !!!")
    number = -1
    while number < 0 or number > second:
        print("File's count must be from 0 to", second, ": ", end = "")
        try:
            number = int(input())
        except ValueError:
            print("It is not a number!")
            number = -1
        else:
            if number < 1 or number > second:
                print("Number must be in range 0 -", second, " !!!")
                number = -1
            else:
                return number