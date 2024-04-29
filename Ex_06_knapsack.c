/*

             EXP 6
AIM:IMPLEMENTION AND ANALYSIS OF FRACTIONAL KNAPSACK PROBLEM.

THEORY:The knapsack problem states that − given a set of items, holding weights and profit values, one must determine the subset of the items to be added in a knapsack such that, the total weight of the items must not exceed the limit of the knapsack and its total profit value is maximum.

It is one of the most popular problems that take greedy approach to be solved. It is called as the Fractional Knapsack Problem.

To explain this problem a little easier, consider a test with 12 questions, 10 marks each, out of which only 10 should be attempted to get the maximum mark of 100. The test taker now must calculate the highest profitable questions – the one that he’s confident in – to achieve the maximum mark. However, he cannot attempt all the 12 questions since there will not be any extra marks awarded for those attempted answers. This is the most basic real-world application of the knapsack problem.

ALGORITHM:
Step 1 -Consider all the items with their weights and profits mentioned respectively.
Step 2 -Calculate Pi/Wi of all the items and sort the items in descending order based on their Pi/Wi values.
Step 3 -Without exceeding the limit, add the items into the knapsack.
Step 4 -If the knapsack can still store some weight, but the weights of other items exceed the limit, the fractional part of the next time can be added.
Step 5 -Hence, giving it the name fractional knapsack problem.

CODE:*/

#include <stdio.h>

#define MAX_ITEMS 10

int capacity, no_items, cur_weight, item;
int used[MAX_ITEMS];
float total_profit;
int weight[MAX_ITEMS];
int value[MAX_ITEMS];

void getUserInput()
{
    printf("Enter the capacity of knapsack:\n");
    scanf("%d", &capacity);

    printf("\nEnter the number of items:\n");
    scanf("%d", &no_items);
}

void getItemsInput()
{
    printf("\nEnter the weight and value of %d item:\n", no_items);
    for (int i = 0; i < no_items; i++)
    {
        printf("Weight[%d]:\t", i);
        scanf("%d", &weight[i]);
        printf("Value[%d]:\t", i);
        scanf("%d", &value[i]);
    }
}

void initialize()
{
    for (int i = 0; i < no_items; ++i)
        used[i] = 0;

    cur_weight = capacity;
    total_profit = 0;
}

void displaySelectedItems()
{
    if (cur_weight >= 0)
        printf("\nAdded object %d (%d Rs., %dKg) completely in the bag. Space left: %d.\n", item + 1, value[item], weight[item], cur_weight);
    else
    {
        int item_percent = (int)((1 + (float)cur_weight / weight[item]) * 100);
        printf("\nAdded %d%% (%d Rs., %dKg) of object %d in the bag.\n", item_percent, value[item], weight[item], item + 1);
        total_profit -= value[item];
        total_profit += (1 + (float)cur_weight / weight[item]) * value[item];
    }
}

void fillKnapsack()
{
    while (cur_weight > 0)
    {
        item = -1;
        for (int i = 0; i < no_items; ++i)
            if ((used[i] == 0) &&
                ((item == -1) || ((float)value[i] / weight[i] > (float)value[item] / weight[item])))
                item = i;

        used[item] = 1;
        cur_weight -= weight[item];
        total_profit += value[item];

        displaySelectedItems();
    }
}

void printResults()
{
    printf("\nFilled the bag with objects worth %.2f Rs.\n", total_profit);
}

int main()
{
    getUserInput();
    getItemsInput();
    initialize();
    fillKnapsack();
    printResults();

    return 0;
}
/*
OUTPUT:
$ ./output_filename.exe
Enter the capacity of knapsack:
3
Enter the number of items:
4
Enter the weight and value of 4 item:
Weight[0]:      100
Value[0]:       2
Weight[1]:      20
Value[1]:       1
Weight[2]:      80
Value[2]:       1
Weight[3]:      60
Value[3]:       3

Added 14% (1 Rs., 20Kg) of object 2 in the bag.

Filled the bag with objects worth 0.15 Rs.

*/