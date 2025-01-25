loadData();
while (1)
{
printf("------------STUDENT MANAGEMENT SYSTEM------------");
printf("\n1. Sign Up\n2. Log In\n3. Add Student (Teacher Only)\n4. Mark
Attendance (Teacher Only)\n5. View Attendance\n6. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
if (choice == 1)
{
printf("Enter username: ");
scanf("%s", usernames[userCount]);
printf("Enter password: ");
scanf("%s", passwords[userCount]);
printf("Is this a teacher? (1 for yes, 0 for no): ");
scanf("%d", &isTeacher[userCount]);
userCount++;
saveData();
}
else if (choice == 2)
{
printf("Enter username: ");
scanf("%s", username);
printf("Enter password: ");
scanf("%s", password);
for (i = 0; i < userCount; i++)
{
int match = 1;
for (j = 0; usernames[i][j] != '\0' && username[j] != '\0'; j++)
{
if (usernames[i][j] != username[j])
{
match = 0;
break;
}
}
if (match && usernames[i][j] == '\0' && username[j] == '\0')
{
match = 1;
for (j = 0; passwords[i][j] != '\0' && password[j] != '\0'; j++)
{
if (passwords[i][j] != password[j])
{
match = 0;
break;
}
}
if (match && passwords[i][j] == '\0' && password[j] == '\0')
{
currentUser = i;
break;
}
}
}
if (currentUser != -1)
{
printf("Logged in as %s\n", isTeacher[currentUser] ? "Teacher" :
"Student");
}
else
{
printf("Invalid credentials\n");
}
}
else if (choice == 3) {
if (currentUser != -1 && isTeacher[currentUser])
{
printf("Enter student ID: ");
scanf("%d", &studentIds[studentCount]);
printf("Enter student name: ");
scanf("%s", studentNames[studentCount]);
for (i = 0; i < 5; i++)
{
studentAttendance[studentCount][i] = 0;
}
studentCount++;
saveData();
}
else
{
printf("You need to log in as a teacher\n");
}
}
else if (choice == 4)
{
if (currentUser != -1 && isTeacher[currentUser])
{
int studentID, subject;
printf("Enter student ID: ");
scanf("%d", &studentID);
for (i = 0; i < studentCount; i++)
{
if (studentIds[i] == studentID)
{
printf("Enter subject (1-5): ");
scanf("%d", &subject);
if (subject >= 1 && subject <= 5)
{
studentAttendance[i][subject - 1] = 1;
printf("Attendance marked for student ID %d, subject %d\n",
studentID, subject);
saveData();
}
else
{
printf("Invalid subject number\n");
}
break;
}
}
if (i == studentCount)
{
printf("Student ID not found\n");
}
}
else
{
printf("You need to log in as a teacher\n");
}
}
else if (choice == 5)
{
if (currentUser != -1)
{
if (isTeacher[currentUser])
{
for (i = 0; i < studentCount; i++)
{
printf("Student ID: %d, Name: %s\n", studentIds[i], studentNames[i]);
for (j = 0; j < 5; j++)
{
printf("Subject %d: %s\n", j + 1, studentAttendance[i][j] ? "Present" :
"Absent");
}
printf("\n");
}
}
else
{
for (i = 0; i < studentCount; i++)
{
if (studentIds[i] == studentIds[currentUser])
{
printf("Your attendance:\n");
for (j = 0; j < 5; j++)
{
printf("Subject %d: %s\n", j + 1, studentAttendance[i][j] ? "Present" :
"Absent");
}
break;
}
}
if (i == studentCount) {
printf("Your attendance data not found\n");
}
}
} else {
printf("You need to log in\n");
}
}
else if (choice == 6)
{
break;
}
else
{
printf("Invalid choice\n");
}
}
}
