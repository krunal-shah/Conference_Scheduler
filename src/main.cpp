/* 
 * File:   main.cpp
 * Author: Kapil Thakkar
 *
 */

#include <cstdlib>
#include "SessionOrganizer.h"

using namespace std;

/*
 * 
 */
int main ( int argc, char** argv )
{
    // Parse the input.
    if ( argc < 3 )
    {   
        cout<<"Missing arguments\n";
        cout<<"Correct format : \n";
        cout << "./main <input_filename> <output_filename>";
        exit ( 0 );
    }
    string inputfilename ( argv[1] );
    
    // Initialize the conference organizer.
    SessionOrganizer *organizer  = new SessionOrganizer(inputfilename);
	//LocalSearch *organizer = new LocalSearch(inputfilename);

    // Organize the papers into tracks based on similarity.
    organizer->organizePapers();

    organizer->printSessionOrganiser(argv[2]);

    // Score the organization against the gold standard.
    double score = organizer->scoreOrganization();
    cout<< "score:"<<score<<endl;
	system("pause");
    return 0;
}

