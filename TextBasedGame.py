# Nathan Feldstein


# Global Variables to reference and update throughout functions
current_room = 'Start'
inventory = []
rooms = {
    'Start': {'east': 'Great Hall'},
    'Great Hall': {'north': 'Kitchen', 'east': 'Formal Dining Room', 'south': 'Bedroom', 'west': 'Start'},
    'Bedroom': {'north': 'Great Hall', 'east': 'Exit'},
    'Exit': {'east': 'Bedroom'},
    'Formal Dining Room': {'north': 'Garden Terrace', 'west': 'Great Hall'},
    'Kitchen': {'south': 'Great Hall', 'east': 'Study'},
    'Study': {'west': 'Kitchen'},
    'Garden Terrace': {'south': 'Formal Dining Room'}
}
# This function will stop the player from moving on without the key in the beginning
def start_no_key():
    global current_room
    global inventory

    while current_room == 'Start' and 'Key' not in inventory:
        print()
        # break the loop if key is picked up
        if 'Key' in inventory:
            break
        print('That key may be helpful for you to get out')
        print('Your current inventory: {}'.format(inventory))
        print('Move Commands: North, South, East, West, or \'q\' for quit')
        user_move = input('Enter your move:\n').lower()

        # Ensure a proper input from the user
        while user_move != 'north' and user_move != 'south' and user_move != 'east' and user_move != 'west' and user_move != 'q':
            print('Enter a valid option')
            print('Move Commands: North, South, East, West, or \'q\' for quit')
            user_move = input('Enter your move:\n').lower()

        # prohibits the user from moving outside the game boundaries (dictionary key values)
        while user_move not in rooms[current_room]:
            print('There is no door or passage that direction and you can\'t go there')
            user_move = input('Enter your move:\n').lower()

        if user_move == 'q':
            print('Goodbye')
            quit()

        # User can't go through the door to the next room without the key
        if user_move == 'east' and 'Key' not in inventory:
            print('door is locked!')
        key = input('Would you like to take the key?(yes/no) ')
        if key == 'yes':
            inventory.append('Key')


# Two ways the game can end outside of user pressing 'q'
def game_over():
    global inventory
    global current_room

    # counts length of inventory list for three items
    if len(inventory) == 3:
        play_again = input(
            'You have collected all the items and were able to escape! would you like to play again? (yes/no)').lower()
        if play_again == 'yes':
            inventory = []
            current_room = 'Start'
            print('You are currently in:', current_room)
            item_check()
        else:
            print('Goodbye')
            quit()

    # Villain placed on the garden terrace
    if current_room == 'Garden Terrace':
        villain_over = input('Game over, you have been captured. Would you like to play again? (yes/no)').lower()
        if villain_over == 'yes':
            inventory = []
            current_room = 'Start'
            print('You are currently in:', current_room)
            item_check()
        else:
            print('Goodbye')
            quit()

#prompts user if they would like to play the game
def play_game():
    name = (input('What is your name? '))  # will use users name in text below

    while True:

        play = str(input('Hi {} would you you like to play a game?(yes/no) '.format(name)).lower())

        if play != 'yes' and play != 'no':
            print('Please enter a valid option')

        #  Welcoming text for user and breaks the loop and moves into the main game loop
        elif play == 'yes':
            print()
            print(' Welcome {} You are trapped in the western room. '
              'I happen to be somewhere in the mansion.\n There are eight rooms total, '
              'some with clues/items including the one you’re in.\n Each one necessary to make it out alive. '
              'Easy, right? To make it harder, \n I will be looking for you along the way and if I do find you- '
              'you will not make it out. Good luck.”'.format(name))
            print()
            break
        elif play == 'no':
            print('Goodbye')
            exit()

# This function checks for items in each room and will append to the global inventory list
def item_check():
    global current_room
    global inventory

    # Checks if user is in the start room and if key is in the inventory
    if current_room == 'Start' and 'Key' not in inventory:
        key = input('You found a Key! Would you like to pick it up? (yes/no) ').lower()
        if key == 'yes':
            inventory.append('Key')
        while key != 'yes' and key != 'no':
            print('Enter a valid option')
            key = input('You found a Key! Would you like to pick it up? (yes/no) ').lower()

    # Checks when user is in the kitchen and if matches are in the inventory
    if current_room == 'Kitchen' and 'Matches' not in inventory:
        matches = input('You found Matches! Would you like to pick it up? (yes/no) ').lower()
        if matches == 'yes':
            inventory.append('Matches')
        while matches != 'yes' and matches != 'no':
            print('Enter a valid option')
            matches = input('You found a Key! Would you like to pick it up? (yes/no) ').lower()

    # Checks if user is in the Great Hall and if the candlestick is in the inventory
    if current_room == 'Great Hall' and 'Candlestick' not in inventory:
        candle = input('You found a Candlestick! Would you like to pick it up? (yes/no) ').lower()
        if candle == 'yes':
            inventory.append('Candlestick')
        while candle != 'yes' and candle != 'no':
            print('Enter a valid option')
            candle = input('You found a Candlestick! Would you like to pick it up? (yes/no) ').lower()
def main():

    global current_room
    global inventory
# Start player here

    # Opens the loop to the main game with user moves
    while True:
        print()
        print('You are currently in:', current_room)
        item_check()
        start_no_key()
        game_over()

        print('Your current inventory: {}'.format(inventory))
        print('Move Commands: North, South, East, West, or \'q\' for quit')

# prompts user to enter their move
        user_move = input('Enter your move:\n' ).lower()


# if not a valid kicks back to top of the loop
        if user_move != 'north' and user_move != 'south' and user_move != 'east' and user_move != 'west' and user_move != 'q':
            print('Enter a valid option')
# End the game
        if user_move == 'q':
            print('Goodbye')
            quit()

# if move is within the dictionary, will update the value of direction key
        elif user_move in rooms[current_room]:
            current_room= rooms[current_room][user_move]

# top of the loop if not a valid option within dictionary
        elif user_move not in rooms[current_room]:
            print('There is no door or passage that direction and you can\'t go there')


play_game()
main()








