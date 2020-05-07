 #include"testheader.h"
 candidate *rootC =NULL;
 void main()
 {
  importData();
  //abhi le liye random value daali hai votes ke liye 
 insertCandidate(&rootC,"NOTA",".",".",".",2);
 insertCandidate(&rootC,"Pushpam Priya Choudhary","Plurals","Flying Horse","F",10);
 insertCandidate(&rootC,"Ram Vilas Paswan","Lok Janashakti Party","RGB Flag","M",12);
 insertCandidate(&rootC,"Tejaswi Yadav","Rashtriya Janata Dal","Lantern","M",12);
 insertCandidate(&rootC,"Nitish Kumar","Janata Dal(United)","Arrow","M",8);
 electionStatistics(&rootC,44);
 }
