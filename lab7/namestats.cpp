// namestats.cpp -- age stats by names
//   usage: namestats name < datafile-of-year-name
// 
//  result: find avg, then range of ages and frequency by age
//  history: revised 2012-10-23 added 'who' to show_freq

#include <iostream>
#include <cstdlib>

using namespace std;


struct Person {
	
    int year;
    string name;
};

const int MAXPEOPLE = 50000;
const int SENTINEL  = -1;
const int NOW       = 2013;

void    read_in_data(Person person[], int sentinel, int array_size);
string  get_name    ();
void	print_ages  (Person person[], int sentinel, string who);
void    do_stats    (Person person[], int sentinel, string who);
int	find_max    (Person person[], int sentinel, string name);
int	find_min    (Person person[], int sentinel, string name);
double	find_avg    (Person person[], int sentinel, string name);
void	show_freq   (Person person[], int sentinal, string name,
                     int min, int max);

int main(int num_args, char *args[])
{
	Person	people[MAXPEOPLE];
	string	name;

	read_in_data(people, SENTINEL, MAXPEOPLE);
	name = args[1];
	print_ages(people, SENTINEL, name);
	do_stats(people, SENTINEL, name);

	return 0;
}

// --- read_in_data ------------------------------------------------------
//  args: array of Person structs, sentinel, max space in array
//  rets: nothing
//  does: reads from cin a year and name, puts sentinel in array
//  errs: calls exit if out of space
//
void read_in_data(Person person[], int sentinel, int space)
{
	int	yr;
	string	nm;
	int	pos = 0;

	do {
		cin >> yr >> nm ;
		if (pos >= space) {
			cerr << "Out of space\n";
			exit(1);
		}
		person[pos].year = yr;
		person[pos].name = nm;
		pos++;
	} while (yr != sentinel);
}

// --- get_name ----------------------------------------------------------
//  purp: read in one name from cin
//  args: none
//  rets: the name
string get_name()
{
    string name;
    cin >> name;
    return name;
}

// --- print_ages -------------------------------------------------------
//  purp: print all ages for the specified name
//  args: an array of structs, the sentinel, the name to find
//  rets: nothing
//  does: prints report to cout
//
void print_ages(Person person[], int sentinel, string who)
{

    for (int i=0; person[i].year != sentinel; i++)
    {
	if (person[i].name == who)
	{
	    cout << NOW - person[i].year << endl;
	}
    }
}

// --- do_stats ----------------------------------------------------------
//  purp: compute and print avg, range AND freq for each age in range
//  args: an array of structs, the sentinel, the name to find
//  rets: nothing
//  does: prints report to cout
//
void do_stats(Person person[], int sentinel, string who)
{
	int	min, max;	// min and max age for 'who'
	double	avg;

	avg = find_avg(person, sentinel, who);
	min = find_min(person, sentinel, who);
	max = find_max(person, sentinel, who);
	cout << "average: " << avg << endl;
	cout << "range: "   << min << "-" << max << endl;
	show_freq(person, sentinel, who, min, max);
}

double find_avg(Person person[], int sent, string name)
{
    double avg = 0.0;
	double total = 0.0;
	int counter = 0;
	for (int i = 0; person[i].year != sent; i++)
	{
	    if (person[i].name == name)
	    {
		total = (total + (NOW - person[i].year));
		counter ++;
	    }
	}
	    avg = total/counter;
        return avg;
}

int find_min(Person person[], int sent, string name)
{

    int curr_year = NOW - person[0].year;
    for (int i=0; person[i].year != sent; i++)
    {
	if (person[i].name == name)
	{
	    if (curr_year > (NOW - person[i].year))
	    {
		curr_year = NOW - person[i].year;
	    }
	}
    }
        return curr_year;
}

int find_max(Person person[], int sent, string name)
{

    int curr_year = NOW - person[0].year;
    for (int i=0; person[i].year != sent; i++)
    {
	if ( person[i].name == name)
	{
	    if (curr_year < (NOW - person[i].year))
	    {
		curr_year = NOW - person[i].year;
	    }
	}
    }
        return curr_year;
}

void show_freq(Person person[], int sent, string who, int min, int max)
{
/*   int counter = 0;
    for (int i=0; person[i].name != sent; i++)
    {
	if (person[i].name == who)
	{
	    if (person[i].year == min)
	    {
		counter++;
	    }
	}
	}*/
//	    return -1;
}
