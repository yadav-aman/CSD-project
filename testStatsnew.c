 #include"testheader.h"
 candidate *rootC =NULL;
 void main()
 {
 insertCandidate(&rootC,"NOTA",".",".",".",2);
 insertCandidate(&rootC,"Pushpam Priya Choudhary","Plurals","Flying Horse","F",10);
 insertCandidate(&rootC,"Ram Vilas Paswan","Lok Janashakti Party","RGB Flag","M",12);
 insertCandidate(&rootC,"Tejasvi Yadav","Rashtriya Janta Dal","Lantern","M",12);
 insertCandidate(&rootC,"Nitish Kumar","Janta Dal(United)","Arrow","M",8);
 electionStatistics(&rootC,44);
 }
