import functions as module

def main():
    ''' Line count must be great then 0 '''
    print("enter number of lines: ", end = "")
    size = module.get_number()

    ''' Create dictionary for string-values '''
    strings = {}
    ''' Create dictionary for number-values '''
    numbers = {}

    ''' Initialize dictionaries '''
    for i in range(size):
        print("Enter key for", i, ": ", end = "")
        key = input()
        print("Enter value for", key, ": ", end = "")
        value = input()
        if value[0].isnumeric():
            numbers[key] = value
        else:
            strings[key] = value

    ''' Create new data structure for key-values and weights '''
    new_strings = module.get_dict_of_weights(strings)
    new_numbers = module.get_dict_of_weights(numbers)
    print("**** Sorted strings by rules ****")

    ''' Print string-value dictionary sorted '''
    while len(new_strings) > 0:
        key = module.get_min_key(new_strings)
        for k, val in new_strings[key].items():
            print(k, val)
        del new_strings[key]

    ''' Print numeric-value dictionary sorted '''
    while len(new_numbers) > 0:
        key = module.get_min_key(new_numbers)
        for k, val in new_numbers[key].items():
            print(k, val)
        del new_numbers[key]

if __name__ == "__main__":
    main()