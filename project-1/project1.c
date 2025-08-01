#include <stdio.h>

void main() {
    float input1 = 0, input2 = 0, answer = 0;
    char opt;
    char more_calculations;

    printf("Welcome to the Calculator program!\n");

    do {
        int valid_operation = 1;
        int valid_operand = 1;

        printf("Enter first number: ");
        scanf("%f", &input1);

        printf("Enter second number: ");
        scanf("%f", &input2);

        do {
            printf("Enter operation (+, -, *, /): ");
            // the previous scanf leaves a \n character in the buffer (after we pressed enter after entering the second input), so we put this \n here to say that the next scan should start reading \n first and then our character. It is a weird behavior. We could also put an empyt space (" ") instead of \n and it'd have the same effect, in this case, discarding the first character and only read the one that we actually input.
            scanf("\n%c", &opt);

            valid_operation = 1;

            switch (opt) {
                case '+':
                    answer = input1 + input2;
                    break;
                case '-':
                    answer = input1 - input2;
                    break;
                case '*':
                    answer = input1 * input2;
                    break;
                case '/':
                    if (input2 == 0) {
                        printf("Second number shouldn't be zero.\n");
                        valid_operand = 0;
                        break;
                    }
                    answer = input1 / input2;
                    break;
                default:
                    printf("Invalid operation.\n");
                    valid_operation = 0;
            }

            if (valid_operand == 0) {
                break;
            }

        } while (valid_operation != 1);

        if (valid_operand == 0) {
            // Give the user a chance to enter valid operands from the beginning
            more_calculations = 'y'; // set to 'y' so the loop can be evaluated to true after the continue statement (because the continue statement will move the code from this point to the while loop validation)
            continue;
        }

        printf("Result: %f %c %f = %f\n", input1, opt, input2, answer);
        printf("Would you like to calculate again? (y/n): ");
        scanf("\n%c", &more_calculations);
    } while (more_calculations == 'y');

    printf("Thank you for using the Calculator program. Goodbye!\n");
}