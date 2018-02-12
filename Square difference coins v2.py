import random
print("Hello, this is subtracting squares game!! \nRules: \nthe game starts with a number between 1 and 50, and players will take turns to subtract from that number a square of numbers from 1 to 6. \nthe Available possible numbers to subtract are: (1,4,9,16,25,36)")
R=1
while R == 1:
    pl= int(input("do you like 1 player or 2 players? \n 1: For 1 player \n 2: For 2 players \n 3: Exit \n "))
    while pl != 1 and pl != 2 and pl != 3:
        pl = int(input("Please enter 1, 2 or 3 only:"))
    n = random.randint(1,50)
    if pl == 1:
        print("The number to start with is ",n)
        while n != 0:
            while True:
                p1 = int(input("Player 1's turn, Enter a number from 1 to 6: "))
                if p1 < 1 or p1 > 6:
                    print("Error!")
                else:
                    if (p1**2)>n:
                        print("Error! You chose to subtract",p1**2, "which is greater than the current number!")
                    else:
                        n -= p1**2
                        print("The number now is :",n)
                        break
            if n == 0:
                print("Player 1 wins!!")
                break
            while True:
                if n == 1 or n == 4 or n == 9 or n == 16 or n == 25 or n == 36:
                    p2 = n
                else:
                    p2 = random.randint(1,6)
                if (p2**2)>n:
                    p2 = random.randint(1,6)
                else:
                    print("Computer's turn, chosen number is: ",p2)
                    n -= p2**2
                    print("The number now is :",n)
                    break
            if n == 0:
                print("Computer wins!!")
                break
    elif pl == 2:
        print("The number to start with is ",n)
        while n != 0:
            while True:
                p1 = int(input("Player 1's turn, Enter a number from 1 to 6: "))
                if p1 < 1 or p1 > 6:
                    print("Error!")
                else:
                    if (p1**2)>n:
                        print("Error! You chose to subtract",p1**2, "which is greater than the current number!")
                    else:
                        n -= p1**2
                        print("The number now is :",n)
                        break
            if n == 0:
                print("Player 1 wins!!")
                break
            while True:
                p2 = int(input("Player 2's turn, Enter a number from 1 to 6: "))
                if p2 < 1 or p2 > 6:
                    print("Error!")
                else:
                    if (p2**2)>n:
                        print("Error! You chose to subtract",p2**2, "which is greater than the current number!")
                    else:
                        n -= p2**2
                        print("The number now is :",n)
                        break
            if n == 0:
                print("Player 2 wins!!")
                break
    elif pl == 3:
        break
    R = int(input("If you would like to play again enter 1!"))
