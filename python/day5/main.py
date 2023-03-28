class Player:
    def __init__(colour):
        this.colour = colour
        elements = {"queen" : 1, "king" : 1, "bishop" : 2, "hours" : 2, "pawn" : 8, "Rook" : 2}

    def remove_element(element):
        if elements[element] > 0:
            elements[element] -= 1
        # Check is not king
        # Check is count == 0, remove from dictionary


class Board:
    __Desk = "Chess"
    def __init__():
        queue = "White"
        board = [["r" "B" "b" "q" "k" "b" "B" "r"],
        ["p", "p", "p", "p", "p", "p", "p", "p"],
        [".", ",",".","." ".", ",",".","."],
        [".", ",",".","." ".", ",",".","."],
        [".", ",",".","." ".", ",",".","."],
        [".", ",",".","." ".", ",",".","."],
        ["P", "P", "P", "P", "P", "P", "P", "P"],
        ["R", "H", "B", "K", "Q", "B", "H", "R"]]

    def is_valid_step(prev_i, prev_j, new_i, new_j):
        # Get element from Board
        # Check is valid step for that figure
        # return True if valid and False in the other case

    def show():
        for i in board:
            for j in i:
                print(j)

    def change_queue():
        if queue == "white":
            queue = "black"
        else:
            queue = "white"


class Instance:
    def __init__(colour, i, j):
        this.colour = colour
        this.i = i
        this.j = j

    @abstractmethod
    def step():
    def step(is_valid_step):
        if (is_valid_step):
            print("Step)))")
            return True

        print("Step failed")
        return False


# Instans

class Bishop(Instance):
    def __init__(colour, i, j):
        super().__init__(colour, i, j)

class Pawn(Instance):
    def __init__(colour, i, j):
        super().__init__(colour, i, j)

class Rook(Instance):
    def __init__(colour, i, j):
        super().__init__(colour, i, j)

class Hours(Instance):
    def __init__(colour, i, j):
        super().__init__(colour, i, j)

class King(Instance):
    def __init__(colour, i, j):
        super().__init__(colour, i, j)

class Queen(Instance):
    def __init__(colour, i, j):
        super().__init__(colour, i, j)