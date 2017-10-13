#ifdef __ROSTER_H__
#define __ROSTER_H__

struct _student_t {
	char * name;
	char ** classes;
	int numClasses;
};
typedef _student_t student_t;

struct _roster_t {
	student_t ** students;
	int numStudents;
};
typedef _roster_t roster_t;

struct _classes_t
{
	char ** classNames;
	int numClasses;
};
typedef _classes_t classes_t;

classes_t * 
#endif