def foo():
    ''' Function has not local variable '''
    pass

def func():
    ''' Has 3 local variables '''
    name = "Mane"
    surname = "kolibri"
    age = 20

def main():
    ''' Run main function to see result '''
    print("Foo function's local variables count is:", foo.__code__.co_nlocals)
    print("Foo function's local variables count is:", func.__code__.co_nlocals)

if __name__ == "__main__":
    main()