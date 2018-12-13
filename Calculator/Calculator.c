//
//  DateNightCalculator.c
//  DateNightCalculator
//
//  Created by Edward Vuong on 9/20/18.
//  Copyright © 2018 Edward Vuong. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

// argv[1] = pizza quantity
// argv[2] = burger quantity
// argv[3] = sushi quantity
// argv[4] = movie ticket quantity

int main(int argc, const char * argv[]) {
    
    int pizzas = 10 * atoi(argv[1]);
    int burgers = 7 * atoi(argv[2]);
    int sushis = 5 * atoi(argv[3]);
    int movies = 12 * atoi(argv[4]);
    
    double dinnerTip = (pizzas + burgers + sushis) * .15;
    double movieTax = movies * .09;
    double movieTotal = movies + movieTax;
    double total = pizzas + burgers + sushis + dinnerTip + movies + movieTax;

    printf("The number of Movie Tickets to purchase is: ");
    printf("%s", argv[4]);
    printf("\nThe price of Movie Tickets before tax is: $");
    printf("%2.2f", (double)movies);
    printf("\nThe number of Movie Tickets with tax is: $");
    printf("%2.2f", movieTotal);
    printf("\nThe total expense for the evening is: $");
    printf("%2.2f\n", total);
    return 0;
}


