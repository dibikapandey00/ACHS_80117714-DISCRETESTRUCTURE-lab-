// Q.No.4 :  Write a program that takes name and age of a 5 persons as an input and
//           gives the degree of membership of the person as its output according to
//           following membership functions.
//                   a. Degree of membership = 1 if age<=20
//                      Degree of membership = (30-age)/10 if age>20 and age<=30
//                      Degree of membership = 0 if age>30
//                   b. Degree of membership = 1 if age<=15
//                      Degree of membership = (35-age)/20 if age>15 and age<=35
//                      Degree of membership = 0 if age>35
//           Perform set operations according to rules of fuzzy sets, on these
//           two sets.



#include <stdio.h>

#define NUM_PERSONS 5

typedef struct {
    char name[50];
    int age;
    float membership1;
    float membership2;
} Person;

float calculate_membership1(int age) {
    if (age <= 20) {
        return 1.0;
    } else if (age > 20 && age <= 30) {
        return (30.0 - age) / 10.0;
    } else {
        return 0.0;
    }
}

float calculate_membership2(int age) {
    if (age <= 15) {
        return 1.0;
    } else if (age > 15 && age <= 35) {
        return (35.0 - age) / 20.0;
    } else {
        return 0.0;
    }
}

int main() {
    Person persons[NUM_PERSONS];

    
    for (int i = 0; i < NUM_PERSONS; i++) {
        printf("Enter name of person %d: ", i + 1);
        scanf("%s", persons[i].name);
        printf("Enter age of person %d: ", i + 1);
        scanf("%d", &persons[i].age);
        
        
        persons[i].membership1 = calculate_membership1(persons[i].age);
        persons[i].membership2 = calculate_membership2(persons[i].age);
    }

    
    printf("\nDegrees of Membership:\n");
    for (int i = 0; i < NUM_PERSONS; i++) {
        printf("%s: Age = %d, Membership1 = %.2f, Membership2 = %.2f\n", 
               persons[i].name, persons[i].age, persons[i].membership1, persons[i].membership2);
    }

    // Perform set operations according to fuzzy set rules
    printf("\nFuzzy Set Operations:\n");
    for (int i = 0; i < NUM_PERSONS; i++) {
        float union_membership = persons[i].membership1 > persons[i].membership2 ? persons[i].membership1 : persons[i].membership2;
        float intersection_membership = persons[i].membership1 < persons[i].membership2 ? persons[i].membership1 : persons[i].membership2;
        float complement_membership1 = 1.0 - persons[i].membership1;
        float complement_membership2 = 1.0 - persons[i].membership2;
        
        printf("%s: Union = %.2f, Intersection = %.2f, Complement1 = %.2f, Complement2 = %.2f\n",
               persons[i].name, union_membership, intersection_membership, complement_membership1, complement_membership2);
    }

    return 0;
}
