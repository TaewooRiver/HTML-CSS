#include "DPmat.h"
#include "string.h"
#include "algorithm"

////////////////////////// A   T   G   C
int scoring_mat[4][4] = {{ 5, -1, -2, -1},
						 {-1,  5, -2, -2},
						 {-2, -2,  5, -3},
						 {-1, -2, -3,  5}};

DPmat::DPmat(){}
DPmat::DPmat(char* input_x, char* input_y)
{
	int i;

	LEN_OF_X = strlen(input_x);
	LEN_OF_Y = strlen(input_y);

	x = new int[LEN_OF_X];
	for(i = 0; i < LEN_OF_X; i++){
		x[i] = chr2int(input_x[i]);
	}

	y = new int[LEN_OF_Y];
	z = new int[LEN_OF_Y];
	for(i = 0; i < LEN_OF_Y; i++){
		y[i] = chr2int(input_y[i]);
		z[i] = 0;
	}

	mat = new Cell* [LEN_OF_X+1];
	for (i = 0; i < LEN_OF_X+1; i++){
		mat[i] = new Cell[LEN_OF_Y+1];
	}

}

int DPmat::chr2int(char chr)
{
	if      ((chr == 'A')||(chr == 'a')) return 1;
	else if ((chr == 'T')||(chr == 't')) return 2;
	else if ((chr == 'G')||(chr == 'g')) return 3;
	else if ((chr == 'C')||(chr == 'c')) return 4;
	else
	{
		cout << "Input Error! NOT valid character(A,T,G,C)" << endl;
		exit(0);
	}
}
char DPmat::int2chr(int num)
{
	if      (num == 0) return '-';
	else if (num == 1) return 'A';
	else if (num == 2) return 'T';
	else if (num == 3) return 'G';
	else if (num == 4) return 'C';
	else
	{
		cout << "Output Error! NOT valid number(0,1,2,3,4)" << endl;
		exit(0);
	}

}
void DPmat::print_z_chr()
{
    // print the value of z as char type and final score of matrix.
    cout << "z: ";
    for(int i = 0; i < LEN_OF_Y; i++){
		cout << int2chr(z[i]);
	}
	cout << "     score: " << mat[LEN_OF_X][LEN_OF_Y].obtain_score() << endl;;
}

void DPmat::print_mat()
{
	cout << "<< score & flag of matrix>>"<< endl;
	int score;
	bool* flg;
	for(int i=0;i<LEN_OF_X+1;i++){
		for(int j=0;j<LEN_OF_Y+1;j++){
			score = mat[i][j].obtain_score();
			flg = mat[i][j].obtain_flag();
			cout << "[";
			for (int k=0; k<3; k++)
			{
				cout << flg[k] <<" ";
			}
			cout << score <<"]"<<"\t";
		}
		cout << "\n";
	}
	cout << endl;

}

void DPmat::fill_in_DPmat()
{
    // Initialize the first low and first column of DPmat
    bool flg[3] = {0,0,0};
    bool flg_row[3] = {1,0,0};
    bool flg_col[3] = {0,0,1};

    mat[0][0].set_scoreflag(0,flg);

    for(int i=1;i<LEN_OF_X+1;i++){
        mat[i][0].set_scoreflag(-6*i,flg_col);
    }
    for(int i=1;i<LEN_OF_Y+1;i++){
        mat[0][i].set_scoreflag(-6*i,flg_row);
    }

    // Fill in the remaining cells of DPmat
    for(int i=1;i<LEN_OF_X+1;i++){
		for(int j=1;j<LEN_OF_Y+1;j++){
            // Choose maximum value among three cases.
            int score = scoring_mat[x[i-1]-1][y[j-1]-1];
            int ij_result_score = max({mat[i-1][j-1].obtain_score()+score, mat[i-1][j].obtain_score() - 6, mat[i][j-1].obtain_score() - 6});

            // Set the flag
            bool flag[3] = {0,0,0};
            if (ij_result_score == mat[i-1][j-1].obtain_score()+score)
                flag[1] = 1;
            if (ij_result_score == mat[i-1][j].obtain_score() - 6)
                flag[2] = 1;
            if (ij_result_score == mat[i][j-1].obtain_score() - 6)
                flag[0] = 1;

            mat[i][j].set_scoreflag(ij_result_score,flag);
        }
    }
}

void DPmat::trace_back(int trace_back_i, int trace_back_j, int trace_back_cnt)
{
    // Recursively tracing back until the end of sequence.
    // Go left at matrix
    if (mat[trace_back_i][trace_back_j].obtain_flag()[0] == 1){
        z[trace_back_cnt] = 0;
        trace_back(trace_back_i,trace_back_j-1,trace_back_cnt-1);
    }
    // Go diagonal(left up) at matrix
    if (mat[trace_back_i][trace_back_j].obtain_flag()[1] == 1){
        z[trace_back_cnt] = x[trace_back_i-1];
        trace_back(trace_back_i-1,trace_back_j-1,trace_back_cnt-1);
    }
    // Go up at matrix
    if (mat[trace_back_i][trace_back_j].obtain_flag()[2] == 1){
        z[trace_back_cnt] = 0;
        trace_back(trace_back_i-1,trace_back_j,trace_back_cnt-1);
    }
    // Print the result at the end of tracing.
    // Similar to ending condition
    if (trace_back_cnt == -1)
        print_z_chr();

}

DPmat::~DPmat()
{
	delete [] x;
	delete [] y;
	delete [] z;

	for(int i = 0; i<LEN_OF_X+1; i++) {
		delete [] mat[i];
	}
	delete [] mat;

}



