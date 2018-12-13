# Date Night Calculator
Due: September 20, 2018</br>

You are a successful programmer and regularly treat your friends to dinner and a movie. Your friends always order Pizzas, Burgers, and Sushi from your favorite restaurant that does not charge tax but you always give a 15% tip. After dinner you go to the movies where 9% sales tax is charged. You always pay with cash so you would like some convenient way to calculate the total expense for the evening so you bring just enough cash. 

The program you create will prompt you to input the amount of each food item and the number of Movie Tickets you will need to purchase.

Make a program that will calculate:
1. Restaurant bill before the tip is added
2. Restaurant Tip amount
3. Restaurant total expense as the food bill plus tip
4. Movie Tickets expense before tax
5. Movie Tickets expense after tax
6. Total expense for the evening

Non taxed item prices:
    Pizza = $10
    Burger = $7
    Sushi = $5

Taxed item prices:
    Movie Ticket = $12

Sample program run is shown as follows:

From the command line:
```
./a.out 1 2 3 6
```
Output:

    1 Pizzas
    2 Burgers
    3 Sushis from the restaurant
    The restaurant bill before tip is: $39.00
    The restaurant bill with tip is: $44.85

    The number of Movie Tickets to purchase is 6.
    The price of Movie Tickets before tax is: $72.00.
    The price of Movie Tickets with tax is: $78.48.
    The total expense for the evening is: $123.33.
    
The program you create must produce outputs that appear exactly as shown.

Create a C program where:
+ Variables have meaningful names and are camel case.
+ Constants have meaningful names and are written in all caps.
+ Printf statements to display messages with integers (whole number values) to indicate the number of each item that will be purchased.
+ Printf statements to display messages showing costs preceded by the dollar sign and 2 decimal places of precision for floating point numbers. 
