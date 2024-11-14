import random as r

listhang=["algorithm","function","variable","compile","iterate","recursion","binary","array","syntax","pointer"]
#game begins
def hangman(): 
 print("WELCOME TO HANGMAN")
 deaths=0
 word=r.choice(listhang)
 #print(word)
 n=len(word)
 guessed= list("-" * n)
 stringposn=0
 while True:
  print("HANGMAN") #7 letters
  print(" "*deaths,end='')
  print("^")
  if stringposn==n:
        print("Phew...you are saved. Congrats!")
        print("Game Over")
        break
  if deaths==6:
        print("DEATH: You have been hanged")
        break
  while True:
    print("Enter your guess for the",stringposn+1,end='')
    guess=input(" letter:")
    if guess.isalpha() and len(guess)==1:
      if guess.lower()==word[stringposn]:
          print("Correct")
          guessed[stringposn]=word[stringposn]
          print("Your current guess:")
          for i in guessed:
            print(i,end="")
          print("")
          stringposn+=1
          break
      else:
          print("Wrong")
          deaths+=1
          break
    else:
     print("Please enter only single letters")
  
  
  
while True:
 hangman()
 choice=input("Do you wish to continue? (y)/ Enter any other key to quit")
 if choice.lower()!='y':
     break
 
 
