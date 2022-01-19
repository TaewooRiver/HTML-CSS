#include "Cell.h"
#include "DPmat.h"

int main()
{
	// basic case
	//char seq_x[] = "TGCTCA";
	//char seq_y[] = "TGCTCGTA";

	// multiple result check case
	//char seq_x[] = "TTCCG";
	//char seq_y[] = "TAACTCG";

	char father[] = "ATGACCGTAATAGGT";
	char can1[] = "AGTGGTAACT";
	char can2[] = "TGACAGTACT";
	char can3[] = "AACCTTGTCT";

	DPmat SA1(can1,father);
	SA1.fill_in_DPmat();

	SA1.print_mat();
	cout<<"y: "<<can1<<endl;
    cout<<"x: "<<father<<endl<<endl;

	SA1.trace_back(SA1.get_LEN_X(), SA1.get_LEN_Y(), SA1.get_LEN_Y()-1);

	cout << endl;

    DPmat SA2(can2,father);
	SA2.fill_in_DPmat();

	SA2.print_mat();
	cout<<"y: "<<can2<<endl;
    cout<<"x: "<<father<<endl<<endl;

	SA2.trace_back(SA2.get_LEN_X(), SA2.get_LEN_Y(), SA2.get_LEN_Y()-1);

	cout << endl;

    DPmat SA3(can3,father);
	SA3.fill_in_DPmat();

	SA3.print_mat();
	cout<<"y: "<<can3<<endl;
    cout<<"x: "<<father<<endl<<endl;

	SA3.trace_back(SA3.get_LEN_X(), SA3.get_LEN_Y(), SA3.get_LEN_Y()-1);
	return 0;
}




