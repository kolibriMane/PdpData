
def is_name(text, line):
    ''' Is primary word '''
    array = line.split(" ")
    if text.count(array[0]) > 1:
        return True
    return False


def get_set(line):
    ''' Get popular words in the sentence '''
    popular_words = set({})
    words = line.split(" ")
    for i in words:
        if i and i[0].isupper():
            popular_words.add(i)

    return popular_words


def normalize_text(text):
    ''' Delete whitespaces '''
    " ".join(text.split())
    ''' Delete spaces after dot '''
    text = text.replace(". ", ".")
    ''' Delete commas '''
    text = text.replace(",", "")
    ''' Split text to sentence '''
    sentences = text.split(".")

    ''' Lambda function to lower only first charecter '''
    to_lower = lambda s: s[:1].lower() + s[1:] if s else ''

    normalized_list = list()
    ''' Check first word is name '''
    for i in sentences:
        if not is_name(text, i):
            normalized_list.append(to_lower(i))
        else :
            normalized_list.append(i)

    return normalized_list

def get_number(second):
    ''' Enter only integer number(not other charecter) '''
    ''' Number must be in range [0, second]'''
    ''' If word count is equal to 0 '''
    if second < 1:
        print("There are not popular words in text !!!")
        return

    print()
    number = -1
    while number < 0 or number > second:
        print('Enter popular words count from 0 to', second, ": ", end = "")
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

def get_max_value(diction):
    ''' Find maximum value from dictionary '''

    ''' If dictionary is empty, nothing to do '''
    if diction == {}:
        return None

    ''' Get first element's value from dictionary and infer it minimum key '''
    ''' For getting element by index used dictionary's keys like list '''
    max_key = list(diction.keys())[0]
    max_value = diction[max_key]

    ''' Count the minimum key and return it '''
    for key, value in diction.items():
        if value > max_value:
            max_value = value
            max_key = key
    return max_key

def get_words(dictionary, count):
    print()
    print("Popular words are -> ", end = "")
    while count > 0:
        key = get_max_value(dictionary)
        print(key, end = " ")
        del dictionary[key]
        count -= 1
    print()