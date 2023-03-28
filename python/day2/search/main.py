import functions as module

def main():
    ''' Input the text, that will be investigated '''
    print("Enter the text: ", end = "")
    text = input()

    normalized_list = module.normalize_text(text)

    word_list = list()
    ''' Split to Array the words and save in set popular words '''
    for i in normalized_list:
        word_list.append(module.get_set(i))

    dictionary = {}
    ''' Add in dictionary popular words with count '''
    ''' All words to lower case to have repeated elements '''
    for i in word_list:
        for key in i:
            if key.lower() in dictionary:
                dictionary[key.lower()] += 1
            else:
                dictionary[key.lower()] = 1

    ''' Get count of popular words '''
    count = module.get_number(len(dictionary))
    if count:
        module.get_words(dictionary, count)

if __name__ == "__main__":
    main()