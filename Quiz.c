#include <stdio.h>

void getQuizData(char questions[][100], char correctAnswers[], int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("Enter question %d: ", i + 1);
        getchar();
        fgets(questions[i], 100, stdin);

        printf("Enter the correct answer: ");
        scanf(" %c", &correctAnswers[i]);
    }
}

void getUserAnswers(char userAnswers[], int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("Your answer for question %d: ", i + 1);
        scanf(" %c", &userAnswers[i]);
    }
}

int calculateScore(char userAnswers[], char correctAnswers[], int count)
{
    int score = 0;
    for (int i = 0; i < count; i++)
    {
        if (userAnswers[i] == correctAnswers[i])
        {
            score++;
        }
    }
    return score;
}

int main()
{
    int count;
    printf("Enter the number of questions you want to add: ");
    scanf("%d", &count);

    char questions[count][100];
    char correctAnswers[count];
    char userAnswers[count];

    printf("Welcome...!!\n");

    getQuizData(questions, correctAnswers, count);

    for (int i = 0; i < count; i++)
    {
        printf("%s", questions[i]);
    }
    getUserAnswers(userAnswers, count);

    int score = calculateScore(userAnswers, correctAnswers, count);

    printf("\nYour total score is: %d out of %d\n", score, count);

    return 0;
}
