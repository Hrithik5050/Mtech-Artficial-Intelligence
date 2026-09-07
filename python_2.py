marks=int(input("Enter your marks: "))
print("Your marks are:", marks)

if marks >= 90:
    print("You are A+ grade student.")
elif marks >= 60:
    print("You are B grade student.")
elif marks >= 40:
    print("You are C grade student.")
elif marks >= 30:
    print("You are just passed ")
else:
    print("You are failed.")