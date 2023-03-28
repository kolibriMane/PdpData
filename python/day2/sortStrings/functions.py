def get_number():
    ''' Enter only integer number(not the other charecter) '''
    ''' Number must be greater then 0 '''
    number = 0
    while number < 1:
        try:
            number = int(input())
        except ValueError:
            ''' If the input value is letter or string '''
            print("It is not a number!")
            print("Try again: ", end = "")
            number = 0
        else:
            ''' If input value is less than or equal to 0 '''
            if number < 1:
                print("Number must be great then 0!")
                print("Try again: ", end = "")
                number = 0
            else:
                return number

''' Key, by witch will be sorted strings '''
def get_dict_of_weights(data):
    new_data = {}
    for string in data.keys():
        count = 0
        ''' Get ASCII codes for strings '''
        l1 = [c for c in string]
        l2 = [ord(c) for c in string]
        for i in l2:
            count += i
        new_data[count] = {string : data[string]}
    return new_data

def get_min_key(diction):
    ''' Find minimum index from dictionary '''
    ''' If dictionary is empty, nothing to do '''
    if diction == {}:
        return None

    ''' Get first element's key from dictionary and infer it minimum key '''
    ''' For getting element by index used dictionary's keys like list '''
    min_key = list(diction.keys())[0]

    ''' Count the minimum key and return it '''
    for key in diction.keys():
        if key < min_key:
            min_key = key
    return min_key