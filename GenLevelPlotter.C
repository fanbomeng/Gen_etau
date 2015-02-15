#define GenLevelPlotter_cxx
#include "GenLevelPlotter.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TColor.h>

void GenLevelPlotter(){

	EColor a=kPink+10;
	EColor b=kAzure;

	TFile* filein= new TFile("ntupleMuTau.root","READONLY");
	TTree *tree =(TTree*)filein->Get("dumpGenInfo/Ntuple");
	GenLevelPlotter t;
	t.Init(tree);
	t.Plots("htaumu_mutau.root",a,false);

	cout<<endl;

	TFile* filein2= new TFile("ntupleTauTau.root","READONLY");
	TTree *tree2 =(TTree*)filein2->Get("dumpGenInfo/Ntuple");
	GenLevelPlotter t2;
	t2.Init(tree2);
	t2.Plots("htautau_mutau.root",b,true);
}


void GenLevelPlotter::Plots(TString fileName, EColor color, bool classic)
{
	//   In a ROOT session, you can do:
	//      Root > .L GenLevelPlotter.C
	//      Root > GenLevelPlotter t
	//      Root > t.GetEntry(12); // Fill t data members with entry number 12
	//      Root > t.Show();       // Show values of entry 12
	//      Root > t.Show(16);     // Read and show values of entry 16
	//      Root > t.Loop();       // Loop on all entries
	//

	//     This is the loop skeleton where:
	//    jentry is the global entry number in the chain
	//    ientry is the entry number in the current Tree
	//  Note that the argument to GetEntry must be:
	//    jentry for TChain::GetEntry
	//    ientry for TTree::GetEntry and TBranch::GetEntry
	//
	//       To read only selected branches, Insert statements like:
	// METHOD1:
	//    fChain->SetBranchStatus("*",0);  // disable all branches
	//    fChain->SetBranchStatus("branchname",1);  // activate branchname
	// METHOD2: replace line
	//    fChain->GetEntry(jentry);       //read all branches
	//by  b_branchname->GetEntry(ientry); //read only this branch
	if (fChain == 0) return;

	TH1F *histoHiggsPt=new TH1F("histoHiggsPt","",1000,0,1000); histoHiggsPt->Sumw2(); histoHiggsPt->SetLineColor(color);
	TH1F *histoHiggsEta=new TH1F("histoHiggsEta","",100,-5,5); histoHiggsEta->Sumw2(); histoHiggsEta->SetLineColor(color);
	TH1F *histoHiggsStatus=new TH1F("histoHiggsStatus","",201,-100,100); histoHiggsStatus->Sumw2(); histoHiggsStatus->SetLineColor(color);
	TH1F *histoHiggsMass=new TH1F("histoHiggsMass","",1000,120,130); histoHiggsMass->Sumw2(); histoHiggsMass->SetLineColor(color);

	TH1F *histoHiggs2Pt=new TH1F("histoHiggs2Pt","",1000,0,1000); histoHiggs2Pt->Sumw2(); histoHiggs2Pt->SetLineColor(color);
	TH1F *histoHiggs2Eta=new TH1F("histoHiggs2Eta","",100,-5,5); histoHiggs2Eta->Sumw2(); histoHiggs2Eta->SetLineColor(color);
	TH1F *histoHiggs2Status=new TH1F("histoHiggs2Status","",201,-100,100); histoHiggs2Status->Sumw2(); histoHiggs2Status->SetLineColor(color);
	TH1F *histoHiggs2Mass=new TH1F("histoHiggs2Mass","",1000,120,130); histoHiggs2Mass->Sumw2(); histoHiggs2Mass->SetLineColor(color);


	TH1F *histoMuonPt=new TH1F("histoMuonPt","",1000,0,1000); histoMuonPt->Sumw2(); histoMuonPt->SetLineColor(color);
	TH1F *histoMuonPlusPt=new TH1F("histoMuonPlusPt","",1000,0,1000); histoMuonPlusPt->Sumw2(); histoMuonPlusPt->SetLineColor(color);
	TH1F *histoMuonMinusPt=new TH1F("histoMuonMinusPt","",1000,0,1000); histoMuonMinusPt->Sumw2(); histoMuonMinusPt->SetLineColor(color);
	TH1F *histoMuonFinalPt=new TH1F("histoMuonFinalPt","",1000,0,1000); histoMuonFinalPt->Sumw2(); histoMuonFinalPt->SetLineColor(color);
	TH1F *histoMuonMinusFinalPt=new TH1F("histoMuonMinusFinalPt","",1000,0,1000); histoMuonMinusFinalPt->Sumw2(); histoMuonMinusFinalPt->SetLineColor(color);
	TH1F *histoMuonPlusFinalPt=new TH1F("histoMuonPlusFinalPt","",1000,0,1000); histoMuonPlusFinalPt->Sumw2(); histoMuonPlusFinalPt->SetLineColor(color);
	TH1F *histoMuonFromTauPt=new TH1F("histoMuonFromTauPt","",1000,0,1000); histoMuonFromTauPt->Sumw2(); histoMuonFromTauPt->SetLineColor(color); 
	TH1F *histoTauPt=new TH1F("histoTauPt","",1000,0,1000); histoTauPt->Sumw2(); histoTauPt->SetLineColor(color);
	TH1F *histoTauMinusPt=new TH1F("histoTauMinusPt","",1000,0,1000); histoTauMinusPt->Sumw2(); histoTauMinusPt->SetLineColor(color);
	TH1F *histoTauPlusPt=new TH1F("histoTauPlusPt","",1000,0,1000); histoTauPlusPt->Sumw2(); histoTauPlusPt->SetLineColor(color);
	TH1F *histoElectronFromTauPt=new TH1F("histoElectronFromTauPt","",1000,0,1000); histoElectronFromTauPt->Sumw2(); histoElectronFromTauPt->SetLineColor(color);
	TH1F *histoTauHadronPt=new TH1F("histoTauHadronPt","",1000,0,1000); histoTauHadronPt->Sumw2(); histoTauHadronPt->SetLineColor(color);

	TH1F *histoMuonStatus1Mom=new TH1F("histoMuonFinalMom","",2001,-1000,1000); histoMuonStatus1Mom->Sumw2(); histoMuonStatus1Mom->SetLineColor(color);
	TH1F *histoElectronStatus1Mom=new TH1F("histoElectronFinalMom","",2001,-1000,1000); histoElectronStatus1Mom->Sumw2(); histoElectronStatus1Mom->SetLineColor(color);

	TH1F *histoMuonEta=new TH1F("histoMuonEta","",100,-5,5); histoMuonEta->Sumw2(); histoMuonEta->SetLineColor(color);
	TH1F *histoMuonFinalEta=new TH1F("histoMuonFinalEta","",100,-5,5); histoMuonFinalEta->Sumw2(); histoMuonFinalEta->SetLineColor(color);
	TH1F *histoMuonFromTauEta=new TH1F("histoMuonFromTauEta","",100,-5,5); histoMuonFromTauEta->Sumw2(); histoMuonFromTauEta->SetLineColor(color);
	TH1F *histoTauEta=new TH1F("histoTauEta","",100,-5,5); histoTauEta->Sumw2(); histoTauEta->SetLineColor(color);
	TH1F *histoElectronFromTauEta=new TH1F("histoElectronFromTauEta","",100,-5,5); histoElectronFromTauEta->Sumw2(); histoElectronFromTauEta->SetLineColor(color);
	TH1F *histoTauHadronEta=new TH1F("histoTauHadronEta","",100,-5,5); histoTauHadronEta->Sumw2(); histoTauHadronEta->SetLineColor(color);

	TH1F *histoMuonPhi=new TH1F("histoMuonPhi","",100,-4,4); histoMuonPhi->Sumw2(); histoMuonPhi->SetLineColor(color);
	TH1F *histoMuonFinalPhi=new TH1F("histoMuonFinalPhi","",100,-4,4); histoMuonFinalPhi->Sumw2(); histoMuonFinalPhi->SetLineColor(color);
	TH1F *histoMuonFromTauPhi=new TH1F("histoMuonFromTauPhi","",100,-4,4); histoMuonFromTauPhi->Sumw2(); histoMuonFromTauPhi->SetLineColor(color);
	TH1F *histoTauPhi=new TH1F("histoTauPhi","",100,-4,4); histoTauPhi->Sumw2(); histoTauPhi->SetLineColor(color);
	TH1F *histoElectronFromTauPhi=new TH1F("histoElectronFromTauPhi","",100,-4,4); histoElectronFromTauPhi->Sumw2(); histoElectronFromTauPhi->SetLineColor(color);
	TH1F *histoTauHadronPhi=new TH1F("histoTauHadronPhi","",100,-4,4); histoTauHadronPhi->Sumw2(); histoTauHadronPhi->SetLineColor(color);

	TH1F *histoNeutrinoSumPt=new TH1F("histoNeutrinoSumPt","",1000,0,1000); histoNeutrinoSumPt->Sumw2(); histoNeutrinoSumPt->SetLineColor(color);


	TH1F *histoPdgIdFinal = new TH1F("histoPdgIdFinal","",2001,-1000,1000); histoPdgIdFinal->Sumw2(); histoPdgIdFinal->SetLineColor(color);

	TH1F* histoFinalMuon_MUTAU= new TH1F ("histoFinalMuon_MUTAU","",1000,0,1000);  histoFinalMuon_MUTAU->Sumw2(); histoFinalMuon_MUTAU->SetLineColor(color);
	TH1F* histoFinalTau_MUTAU= new TH1F ("histoFinalTau_MUTAU","",1000,0,1000);  histoFinalTau_MUTAU->Sumw2(); histoFinalTau_MUTAU->SetLineColor(color);
	TH1F* histoFinalMuon_MUELE= new TH1F ("histoFinalMuon_MUELE","",1000,0,1000);  histoFinalMuon_MUELE->Sumw2(); histoFinalMuon_MUELE->SetLineColor(color);
	TH1F* histoFinalElectron_MUELE= new TH1F ("histoFinalElectron_MUELE","",1000,0,1000);  histoFinalElectron_MUELE->Sumw2(); histoFinalElectron_MUELE->SetLineColor(color);

	TH1F* histoDeltaNeutrinoMuon_MUELE=new TH1F("histoDeltaNeutrinoMuon_MUELE","",100,0,7); histoDeltaNeutrinoMuon_MUELE->Sumw2(); histoDeltaNeutrinoMuon_MUELE->SetLineColor(color);
	TH1F* histoDeltaNeutrinoMuon_MUTAU=new TH1F("histoDeltaNeutrinoMuon_MUTAU","",100,0,7); histoDeltaNeutrinoMuon_MUTAU->Sumw2(); histoDeltaNeutrinoMuon_MUTAU->SetLineColor(color);
	TH1F* histoDeltaNeutrinoElectron_MUELE=new TH1F("histoDeltaNeutrinoElectron_MUELE","",100,0,7); histoDeltaNeutrinoElectron_MUELE->Sumw2(); histoDeltaNeutrinoElectron_MUELE->SetLineColor(color);
	TH1F* histoDeltaNeutrinoTau_MUTAU=new TH1F("histoDeltaNeutrinoTau_MUTAU","",100,0,7); histoDeltaNeutrinoTau_MUTAU->Sumw2(); histoDeltaNeutrinoTau_MUTAU->SetLineColor(color);
	TH1F* histoDeltaTauMuon_MUTAU=new TH1F("histoDeltaTauMuon_MUTAU","",100,0,7); histoDeltaTauMuon_MUTAU->Sumw2(); histoDeltaTauMuon_MUTAU->SetLineColor(color);
	TH1F* histoDeltaElectronMuon_MUELE=new TH1F("histoDeltaElectronMuon_MUELE","",100,0,7); histoDeltaElectronMuon_MUELE->Sumw2(); histoDeltaElectronMuon_MUELE->SetLineColor(color);

	TH1F* histoMuon_MUTAU_selected= new TH1F ("histoMuon_MUTAU_selected","",1000,0,1000);  histoMuon_MUTAU_selected->Sumw2(); histoMuon_MUTAU_selected->SetLineColor(color);
	TH1F* histoTau_MUTAU_selected= new TH1F ("histoTau_MUTAU_selected","",1000,0,1000);  histoTau_MUTAU_selected->Sumw2(); histoTau_MUTAU_selected->SetLineColor(color);
	TH1F* histoHiggs_MUTAU_selected= new TH1F ("histoHiggs_MUTAU_selected","",1000,0,1000);  histoHiggs_MUTAU_selected->Sumw2(); histoHiggs_MUTAU_selected->SetLineColor(color);  
	TH1F* histoHiggs_MUTAU_selected_2= new TH1F ("histoHiggs_MUTAU_selected_2","",1000,0,1000);  histoHiggs_MUTAU_selected_2->Sumw2(); histoHiggs_MUTAU_selected_2->SetLineColor(color);
	TH1F* histoTau2_MUTAU_selected= new TH1F ("histoTau2_MUTAU_selected","",1000,0,1000);  histoTau2_MUTAU_selected->Sumw2(); histoTau2_MUTAU_selected->SetLineColor(color);
	TH2F* histo2D_MUTAU= new TH2F ("histo2D_MUTAU","",1000,0,1000,1000,0,1000); histo2D_MUTAU->Sumw2(); histo2D_MUTAU->SetLineColor(color); histo2D_MUTAU->SetMarkerColor(color);


	TH1F* histoMuon_MUTAU_selectedTight= new TH1F ("histoMuon_MUTAU_selectedTight","",1000,0,1000);  histoMuon_MUTAU_selectedTight->Sumw2(); histoMuon_MUTAU_selectedTight->SetLineColor(color);
	TH1F* histoTau_MUTAU_selectedTight= new TH1F ("histoTau_MUTAU_selectedTight","",1000,0,1000);  histoTau_MUTAU_selectedTight->Sumw2(); histoTau_MUTAU_selectedTight->SetLineColor(color);
	TH1F* histoHiggs_MUTAU_selectedTight= new TH1F ("histoHiggs_MUTAU_selectedTight","",1000,0,1000);  histoHiggs_MUTAU_selectedTight->Sumw2(); histoHiggs_MUTAU_selectedTight->SetLineColor(color);
	TH1F* histoHiggs_MUTAU_selectedTight_2= new TH1F ("histoHiggs_MUTAU_selectedTight_2","",1000,0,1000);  histoHiggs_MUTAU_selectedTight_2->Sumw2(); histoHiggs_MUTAU_selectedTight_2->SetLineColor(color);
	TH1F* histoTau2_MUTAU_selectedTight= new TH1F ("histoTau2_MUTAU_selectedTight","",1000,0,1000);  histoTau2_MUTAU_selectedTight->Sumw2(); histoTau2_MUTAU_selectedTight->SetLineColor(color);


	Long64_t nentries = fChain->GetEntriesFast();


	Long_t mutau_classic=0, eletau_classic=0, mumu_classic=0, muele_classic=0, eleele_classic=0, tautau_classic=0;
	Long_t mutau_lfv=0,  muele_lfv=0, mumu_lfv=0;
	Long_t fallo=0;
	Long_t hadronic=0;

	Long_t tautau_byhadrons=0, tauplus_byhadrons=0, tauminus_byhadrons=0, notaus_byhadrons=0;

	Long64_t nbytes = 0, nb = 0;

	//   nentries=100000;
	printf("Running over %d \n",nentries);

	double HiggsPT=0, HiggsPT2=0;

	for (Long64_t jentry=0; jentry<nentries;jentry++) {
		if(jentry%1000==0) printf("\t\t %4d \n",jentry);
		Long64_t ientry = LoadTree(jentry);
		if (ientry < 0) break;
		nb = fChain->GetEntry(jentry);   nbytes += nb;

		double neutrinoPx=0, neutrinoPy=0;

		int tau_mu_decay=0, tau_ele_decay=0;

		bool found_tauplus_hadron=0;	
		bool found_tauminus_hadron=0;

		double finalMuonPt=0, finalElectronPt=0, finalTauPtPlus=0, finalTauPtMinus=0;
		double finalMuonPhi=0, finalElectronPhi=0, finalTauPhiPlus=0, finalTauPhiMinus=0;

		bool hadronTauPlus=false, eleFromTauPlus=false;

		//cout<<endl<<endl<<" EVENT "<<jentry<<endl;

		bool plotted2ndHiggs=false;	

		for(int i=0; i<pt->size();i++){

			if(pdgId->at(i)==25){

				if ( (!classic && status->at(i)>60)  || (classic && status->at(i)==3) ) {
					histoHiggsMass->Fill(mass->at(i));
					histoHiggsPt->Fill(pt->at(i));
					histoHiggsEta->Fill(eta->at(i));
					histoHiggsStatus->Fill(status->at(i));
					//		cout<<evt<<"   FINAL   "<<pt->at(i)<<"   "<<mass->at(i)<<"    "<<status->at(i)<<endl;
					HiggsPT=pt->at(i);
				}
				else if ( (!classic &&  status->at(i)>40 && status->at(i)<60) || (classic && status->at(i)==2) ) {
					//              cout<<evt<<" \t    Others   "<<pt->at(i)<<"   "<<mass->at(i)<<"    "<<status->at(i)<<endl;
					if(plotted2ndHiggs) continue;
					plotted2ndHiggs=true;
					histoHiggs2Mass->Fill(mass->at(i));
					histoHiggs2Pt->Fill(pt->at(i));
					histoHiggs2Eta->Fill(eta->at(i));
					histoHiggs2Status->Fill(status->at(i));
					HiggsPT2=pt->at(i);
				}
			}	

			if(motherPdgId->at(i)==25){
				if(abs(pdgId->at(i))==13){
					histoMuonPt->Fill(pt->at(i));
					histoMuonEta->Fill(eta->at(i));	
					histoMuonPhi->Fill(phi->at(i));
					if(pdgId->at(i)==13) histoMuonPlusPt->Fill(pt->at(i));
					else histoMuonMinusPt->Fill(pt->at(i));
				}
				if(abs(pdgId->at(i))==15){
					histoTauPt->Fill(pt->at(i));
					histoTauEta->Fill(eta->at(i));
					histoTauPhi->Fill(phi->at(i));
					if(pdgId->at(i)==15) histoTauPlusPt->Fill(pt->at(i));
					else histoTauMinusPt->Fill(pt->at(i));
				}
			}
			if(status->at(i)==2&& abs(pdgId->at(i))==15){
				histoTauHadronPt->Fill(pt->at(i));
				histoTauHadronEta->Fill(eta->at(i));
				histoTauHadronPhi->Fill(phi->at(i));
				if(pdgId->at(i)==15) found_tauplus_hadron=true;
				if(pdgId->at(i)==-15) found_tauminus_hadron=true;
				if(pdgId->at(i)>0){ 
					finalTauPtPlus=pt->at(i);
					finalTauPhiPlus=phi->at(i);
				}
				else {
					finalTauPtMinus=pt->at(i);
					finalTauPhiMinus=phi->at(i);
				}

				//cout<<"Tau Hadron:  "<<pdgId->at(i)<<"   "<<pt->at(i)<<"   "<<phi->at(i)<<"    "<<eta->at(i)<<endl;
			}
			if(status->at(i)==1){	
				histoPdgIdFinal->Fill(pdgId->at(i));
				if(abs(pdgId->at(i))==13)  histoMuonStatus1Mom->Fill(motherPdgId->at(i));
				if(abs(pdgId->at(i))==11)  histoElectronStatus1Mom->Fill(motherPdgId->at(i));

				if(abs(pdgId->at(i))==13 && ((abs(motherPdgId->at(i))==13 || motherPdgId->at(i)==25))){
					histoMuonFinalPt->Fill(pt->at(i));
					histoMuonFinalEta->Fill(eta->at(i));
					histoMuonFinalPhi->Fill(phi->at(i));
					if(finalMuonPt==0){
						finalMuonPt=pt->at(i);
						finalMuonPhi=phi->at(i);
					}
					if( pdgId->at(i) >0  )hadronTauPlus=false;
					else hadronTauPlus=true;
					//cout<<"Muon:  "<<pdgId->at(i)<<"   "<<pt->at(i)<<"   "<<phi->at(i)<<"    "<<eta->at(i)<<endl;

				}
				if(abs(pdgId->at(i))==13 && abs(motherPdgId->at(i))==15){
					histoMuonFromTauPt->Fill(pt->at(i));
					histoMuonFromTauEta->Fill(eta->at(i));
					histoMuonFromTauPhi->Fill(phi->at(i));
					tau_mu_decay++;
					if(finalMuonPt==0){
						finalMuonPt=pt->at(i);
						finalMuonPhi=phi->at(i);
					}
					if( motherPdgId->at(i) >0  )hadronTauPlus=true;
					else hadronTauPlus=false;
					//cout<<"Muon From Tau:  "<<pdgId->at(i)<<"   "<<pt->at(i)<<"   "<<phi->at(i)<<"    "<<eta->at(i)<<endl;
				}
				if(abs(pdgId->at(i))==11 && abs(motherPdgId->at(i))==15){
					histoElectronFromTauPt->Fill(pt->at(i));
					histoElectronFromTauEta->Fill(eta->at(i));
					histoElectronFromTauPhi->Fill(phi->at(i));
					tau_ele_decay++;
					if(finalElectronPt==0){
						finalElectronPt=pt->at(i);
						finalElectronPhi=phi->at(i);
					}
					if( motherPdgId->at(i) >0  )eleFromTauPlus=true;
					else eleFromTauPlus=false;

				}
				if(abs(pdgId->at(i))==12 || abs(pdgId->at(i))==14 || abs(pdgId->at(i))==16) {
					neutrinoPx+=pt->at(i)*cos(phi->at(i));
					neutrinoPy+=pt->at(i)*sin(phi->at(i));
					//cout<<"Neutrino -->"<<pdgId->at(i)<<"   "<<pt->at(i)<<"    "<<phi->at(i)<<"   "<<eta->at(i)<<endl;
				}
			}
		}
		histoNeutrinoSumPt->Fill(sqrt(neutrinoPx*neutrinoPx+neutrinoPy*neutrinoPy));

		double neutrinoSumPhi=atan(neutrinoPy/neutrinoPx);
		if (neutrinoPy>0 && neutrinoPx<0)  neutrinoSumPhi=3.14-atan(fabs(neutrinoPy/neutrinoPx));
		if (neutrinoPy<0 && neutrinoPx<0)  neutrinoSumPhi=-3.14+atan(neutrinoPy/neutrinoPx);

		//cout<<"Neutrino Px,Py: "<<neutrinoPx<<"  "<<neutrinoPy<<endl;
		//cout<<"NeutrinoSum  -->"<<sqrt(neutrinoPx*neutrinoPx+neutrinoPy*neutrinoPy)<<"   "<<neutrinoSumPhi<<endl;

		double finalTauPt=0, finalTauPhi=0;
		double decayedTauPt=0, decayedTauPhi=0;
		if(hadronTauPlus) {
			if(!classic){
				finalTauPt=finalTauPtPlus; finalTauPhi=finalTauPhiPlus;
			}
			else{
				finalTauPt=finalTauPtMinus; finalTauPhi=finalTauPhiMinus;
				decayedTauPt=finalTauPtPlus;  decayedTauPhi=finalTauPhiPlus;}
		}
		else {
			if(!classic){
				finalTauPt=finalTauPtMinus; finalTauPhi=finalTauPhiMinus;}
			else{
				finalTauPt=finalTauPtPlus; finalTauPhi=finalTauPhiPlus;
				decayedTauPt=finalTauPtMinus;  decayedTauPhi=finalTauPhiMinus;
			}
		}

		double deltaPhiMuonNeutrino=fabs(finalMuonPhi-neutrinoSumPhi);
		if (deltaPhiMuonNeutrino>=3.14) deltaPhiMuonNeutrino=2*3.14-deltaPhiMuonNeutrino;
		double deltaPhiElectronNeutrino=fabs(finalElectronPhi-neutrinoSumPhi);
		if (deltaPhiElectronNeutrino>=3.14) deltaPhiElectronNeutrino=2*3.14-deltaPhiElectronNeutrino;
		double deltaPhiMuonElectron=fabs(finalMuonPhi-finalElectronPhi);
		if (deltaPhiMuonElectron>=3.14) deltaPhiMuonElectron=2*3.14-deltaPhiMuonElectron;
		double deltaPhiMuonTau=fabs(finalMuonPhi-finalTauPhi);
		if (deltaPhiMuonTau>=3.14) deltaPhiMuonTau=2*3.14-deltaPhiMuonTau;
		double deltaPhiTauNeutrino=fabs(finalTauPhi-neutrinoSumPhi);
		if (deltaPhiTauNeutrino>=3.14) deltaPhiTauNeutrino=2*3.14-deltaPhiTauNeutrino;


		//cout<<"deltaPhiMuonNeutrino -->"<<deltaPhiMuonNeutrino<<endl;
		//cout<<"deltaPhiTauNeutrino -->"<<deltaPhiTauNeutrino<<endl;
		//cout<<"deltaPhiMuonTau -->"<<deltaPhiMuonTau<<endl;


		if (classic){
			if(tau_mu_decay==1 && tau_ele_decay==0 )      mutau_classic++;
			else if(tau_ele_decay==1 && tau_mu_decay==0 ) eletau_classic++;
			else if(tau_mu_decay==1 && tau_ele_decay==1 )  muele_classic++;
			else if(tau_mu_decay==1 && tau_ele_decay==1 )  muele_classic++;
			else if(tau_mu_decay==2) mumu_classic++;
			else if(tau_ele_decay==2) eleele_classic++;
			else if( tau_mu_decay>0 || tau_ele_decay>0) fallo++;
			else tautau_classic++;
		}
		else{
			if(tau_mu_decay==1 && tau_ele_decay==0) mumu_lfv++;
			else if(tau_ele_decay==1 && tau_mu_decay==0 ) muele_lfv++;
			else if ( tau_mu_decay>0 || tau_ele_decay>0) fallo++;
			else mutau_lfv++;
		}
		if(found_tauminus_hadron && found_tauplus_hadron) tautau_byhadrons++;
		if(found_tauminus_hadron && !found_tauplus_hadron) tauminus_byhadrons++;
		if(!found_tauminus_hadron && found_tauplus_hadron) tauplus_byhadrons++;
		if(!found_tauminus_hadron && !found_tauplus_hadron) notaus_byhadrons++;

		// Observed



		if(classic&&tau_mu_decay==1 && tau_ele_decay==0) {
			histoFinalMuon_MUTAU->Fill(finalMuonPt);
			histoFinalTau_MUTAU->Fill(finalTauPt);
			histoDeltaNeutrinoMuon_MUTAU->Fill(deltaPhiMuonNeutrino);
			histoDeltaNeutrinoTau_MUTAU->Fill(deltaPhiTauNeutrino);
			histoDeltaTauMuon_MUTAU->Fill(deltaPhiMuonTau);
		}
		if(classic&&tau_mu_decay==1 && tau_ele_decay==1) {
			histoFinalMuon_MUELE->Fill(finalMuonPt);
			histoFinalElectron_MUELE->Fill(finalElectronPt);
			histoDeltaNeutrinoMuon_MUELE->Fill(deltaPhiMuonNeutrino);
			histoDeltaNeutrinoElectron_MUELE->Fill(deltaPhiTauNeutrino);
			histoDeltaElectronMuon_MUELE->Fill(deltaPhiMuonTau);
		}
		if(!classic && tau_ele_decay==1 && tau_mu_decay==0){
			histoFinalMuon_MUELE->Fill(finalMuonPt);
			histoFinalElectron_MUELE->Fill(finalElectronPt);
			histoDeltaNeutrinoMuon_MUELE->Fill(deltaPhiMuonNeutrino);
			histoDeltaNeutrinoElectron_MUELE->Fill(deltaPhiTauNeutrino);
			histoDeltaElectronMuon_MUELE->Fill(deltaPhiMuonTau);
		}
		if(!classic && tau_ele_decay==0 && tau_mu_decay==0){
			histoFinalMuon_MUTAU->Fill(finalMuonPt);
			histoFinalTau_MUTAU->Fill(finalTauPt);
			histoDeltaNeutrinoMuon_MUTAU->Fill(deltaPhiMuonNeutrino);
			histoDeltaNeutrinoTau_MUTAU->Fill(deltaPhiTauNeutrino);
			histoDeltaTauMuon_MUTAU->Fill(deltaPhiMuonTau);
		}

		// Selected 
		bool selected=false;

		histo2D_MUTAU->Fill(finalTauPt,finalMuonPt);

		if (!classic && tau_ele_decay==0 && tau_mu_decay==0 && finalTauPt>20   && finalMuonPt >20  ) selected=true;
		if (classic && tau_mu_decay==1 && tau_ele_decay==0 &&  finalTauPt>20   && finalMuonPt >20  ) selected=true;

		if(!selected) continue;

		histoMuon_MUTAU_selected->Fill(finalMuonPt);
		histoTau_MUTAU_selected->Fill(finalTauPt);
		histoTau2_MUTAU_selected->Fill(decayedTauPt);
		histoHiggs_MUTAU_selected->Fill(HiggsPT);
		histoHiggs_MUTAU_selected_2->Fill(HiggsPT2);

		selected=false;

		if (!classic && tau_ele_decay==0 && tau_mu_decay==0 && finalTauPt>40   && finalMuonPt >40  ) selected=true;
		if (classic && tau_mu_decay==1 && tau_ele_decay==0 &&  finalTauPt>40   && finalMuonPt >40  ) selected=true;

		if(!selected) continue;

		histoMuon_MUTAU_selectedTight->Fill(finalMuonPt);
		histoTau_MUTAU_selectedTight->Fill(finalTauPt);
		histoTau2_MUTAU_selectedTight->Fill(decayedTauPt);
		histoHiggs_MUTAU_selectedTight->Fill(HiggsPT);
		histoHiggs_MUTAU_selectedTight_2->Fill(HiggsPT2);


	}
	if(classic){
		cout<<"H2TAU"<<endl;
		cout<<"==================="<<endl;	
		cout<<"MuTau:  "<<mutau_classic<<endl;
		cout<<"EleTau:  "<<eletau_classic<<endl;
		cout<<"MuMu:  "<<mumu_classic<<endl;
		cout<<"EleEle:  "<<eleele_classic<<endl;
		cout<<"MuEle:  "<<muele_classic<<endl;
		cout<<"TauTau:  "<<tautau_classic<<endl;
	}
	else{		
		cout<<"HMUTAU"<<endl;
		cout<<"==================="<<endl;
		cout<<"MuTau:  "<<mutau_lfv<<endl;
		cout<<"MuMu:  "<<mumu_lfv<<endl;
		cout<<"MuEle:  "<<muele_lfv<<endl;
	}
	cout<<"By Hadrons:"<<endl;
	cout<<"TauTau:   "<<tautau_byhadrons<<endl;
	cout<<"TauPlus:   "<<tauplus_byhadrons<<endl;
	cout<<"TauMinus:   "<<tauminus_byhadrons<<endl;
	cout<<"NoTaus:   "<<notaus_byhadrons<<endl;



	TFile *outfile = new TFile(fileName,"RECREATE");
	histoMuonPt->Write();
	histoMuonEta->Write();
	histoMuonPhi->Write();
	histoTauPt->Write();
	histoTauEta->Write();
	histoTauPhi->Write();
	histoMuonFinalPt->Write();
	histoMuonFinalEta->Write();
	histoMuonFinalPhi->Write();
	histoMuonFromTauPt->Write();
	histoMuonFromTauEta->Write();
	histoMuonFromTauPhi->Write();
	histoElectronFromTauPt->Write();
	histoElectronFromTauEta->Write();
	histoElectronFromTauPhi->Write();
	histoNeutrinoSumPt->Write();
	histoPdgIdFinal->Write();
	histoTauHadronPt->Write();
	histoTauHadronEta->Write();
	histoTauHadronPhi->Write();
	histoMuonStatus1Mom->Write();
	histoElectronStatus1Mom->Write();
	histoMuonMinusPt->Write(); histoMuonPlusPt->Write();	
	histoTauMinusPt->Write(); histoTauPlusPt->Write();    

	histoFinalElectron_MUELE->Write();
	histoFinalMuon_MUELE->Write();
	histoFinalMuon_MUTAU->Write();
	histoFinalTau_MUTAU->Write();

	histoDeltaNeutrinoMuon_MUELE    ->Write();
	histoDeltaNeutrinoElectron_MUELE->Write();
	histoDeltaElectronMuon_MUELE    ->Write();
	histoDeltaNeutrinoMuon_MUTAU    ->Write();
	histoDeltaNeutrinoTau_MUTAU     ->Write();
	histoDeltaTauMuon_MUTAU         ->Write();

	histoHiggsPt->Write();
	histoHiggsStatus->Write();
	histoHiggsEta->Write();
	histoHiggsMass->Write();

	histoHiggs2Pt->Write();
	histoHiggs2Status->Write();
	histoHiggs2Eta->Write();
	histoHiggs2Mass->Write();

	histoTau2_MUTAU_selected->Write();
	histoMuon_MUTAU_selected->Write();
	histoTau_MUTAU_selected->Write();
	histoHiggs_MUTAU_selected->Write();
	histoHiggs_MUTAU_selected_2->Write();
	histo2D_MUTAU->Write();

	histoTau2_MUTAU_selectedTight->Write();
	histoMuon_MUTAU_selectedTight->Write();
	histoTau_MUTAU_selectedTight->Write();
	histoHiggs_MUTAU_selectedTight->Write();
	histoHiggs_MUTAU_selectedTight_2->Write();
}
