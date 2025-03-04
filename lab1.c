int calculate(char* s) {
    int stack[150000];
    int top = -1;
    int num = 0;
    int result = 0;
    int n1, n2;
    char last_operator = '+';

    for (int i = 0; s[i] != '\0'; i++) {
        char current_char = s[i];

        if (isdigit(current_char)) {
            num = num * 10 + (current_char - '0');
        }

        if ((!isdigit(current_char) && current_char != ' ') || s[i+1] == '\0') {
            switch (last_operator) {
                case '+':
                    stack[++top] = num;
                    break;
                case '-':
                    stack[++top] = -num;
                    break;
                case '*':
                    n1 = stack[top--];
                    stack[++top] = n1 * num;
                    break;
                case '/':
                    n1 = stack[top--];
                    stack[++top] = n1 / num;
                    break;
            }
            num = 0;
            last_operator = current_char;
        }
    }

    for (int i = 0; i <= top; i++) {
        result += stack[i];
    }

    return result;
}
