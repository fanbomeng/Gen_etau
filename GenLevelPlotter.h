//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Feb  5 23:38:11 2014 by ROOT version 5.34/02
// from TTree Ntuple/Ntuple
// found on file: testGenHMuTau_2000.root
//////////////////////////////////////////////////////////

#ifndef GenLevelPlotter_h
#define GenLevelPlotter_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <vector>
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.

class GenLevelPlotter {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   vector<float>   *pt;
   vector<float>   *eta;
   vector<float>   *phi;
   vector<float>   *mass;
   vector<int>     *status;
   vector<long>    *pdgId;
   vector<int>     *motherStatus;
   vector<long>    *motherPdgId;
   vector<int>     *numberOfDaughters;
   ULong64_t       evt;

   // List of branches
   TBranch        *b_pt;   //!
   TBranch        *b_eta;   //!
   TBranch        *b_phi;   //!
   TBranch        *b_mass;   //!
   TBranch        *b_status;   //!
   TBranch        *b_pdgId;   //!
   TBranch        *b_motherStatus;   //!
   TBranch        *b_motherPdgId;   //!
   TBranch        *b_numberOfDaughters;   //!
   TBranch        *b_evt;   //!

   GenLevelPlotter(TTree *tree=0);
   virtual ~GenLevelPlotter();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef GenLevelPlotter_cxx
GenLevelPlotter::GenLevelPlotter(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("testGenHMuTau_2000.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("testGenHMuTau_2000.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("testGenHMuTau_2000.root:/dumpGenInfo");
      dir->GetObject("Ntuple",tree);

   }
   Init(tree);
}

GenLevelPlotter::~GenLevelPlotter()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t GenLevelPlotter::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t GenLevelPlotter::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void GenLevelPlotter::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   pt = 0;
   eta = 0;
   phi = 0;
   mass = 0;
   status = 0;
   pdgId = 0;
   motherStatus = 0;
   motherPdgId = 0;
   numberOfDaughters = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("pt", &pt, &b_pt);
   fChain->SetBranchAddress("eta", &eta, &b_eta);
   fChain->SetBranchAddress("phi", &phi, &b_phi);
   fChain->SetBranchAddress("mass", &mass, &b_mass);
   fChain->SetBranchAddress("status", &status, &b_status);
   fChain->SetBranchAddress("pdgId", &pdgId, &b_pdgId);
   fChain->SetBranchAddress("motherStatus", &motherStatus, &b_motherStatus);
   fChain->SetBranchAddress("motherPdgId", &motherPdgId, &b_motherPdgId);
   fChain->SetBranchAddress("numberOfDaughters", &numberOfDaughters, &b_numberOfDaughters);
   fChain->SetBranchAddress("evt", &evt, &b_evt);
   Notify();
}

Bool_t GenLevelPlotter::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void GenLevelPlotter::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t GenLevelPlotter::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef GenLevelPlotter_cxx
