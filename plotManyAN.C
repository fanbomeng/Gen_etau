{


  gROOT->LoadMacro("tdrstyle.C");
  setTDRStyle();
  gStyle->SetOptStat(0);


  gROOT->LoadMacro("plotMuTau.C");


  plotMuTau("LFVvsSMH_HiggsPt_TIGHT","histoHiggs_MUTAU_selectedTight","histoHiggs_MUTAU_selectedTight","Higgs p_{T} [GeV]","a.u.",0,200,1,false,0.5,0.99,0.9,0.75,"",true);

  plotMuTau("LFVvsSMH_HiggsPt_SELECTED","histoHiggs_MUTAU_selected","histoHiggs_MUTAU_selected","Higgs p_{T} [GeV]","a.u.",0,200,1,false,0.5,0.99,0.9,0.75,"",true);
  plotMuTau("LFVvsSMH_HiggsPt_MIX","histoHiggs_MUTAU_selectedTight","histoHiggs_MUTAU_selected","Higgs p_{T} [GeV]","a.u.",0,200,1,false,0.5,0.99,0.9,0.75,"",true);

  plotMuTau("LFVvsSMH_HiggsPt_TIGHT","histoHiggs_MUTAU_selectedTight","histoHiggs_MUTAU_selectedTight","Higgs p_{T} [GeV]","a.u.",0,200,1,false,0.5,0.99,0.9,0.75,"",true);
  plotMuTau("LFVvsSMH_HiggsPt_TIGHT","histoHiggs_MUTAU_selectedTight","histoHiggs_MUTAU_selected","Higgs p_{T} [GeV]","#sigma x Br [pb] / 5 GeV",0,200,1,false,0.5,0.99,0.9,0.75,"");
  plotMuTau("LFVvsSMH_HiggsPt_TIGHT_status2","histoHiggs_MUTAU_selectedTight_2","histoHiggs_MUTAU_selected_2","Higgs p_{T} [GeV]","#sigma x Br [pb] / 5 GeV",0,200,1,false,0.5,0.99,0.9,0.75,"");
  plotMuTau("LFVvsSMH_HiggsPt_TIGHT_status2","histoHiggs_MUTAU_selectedTight_2","histoHiggs_MUTAU_selected_2","Higgs p_{T} [GeV]","a.u.",0,200,1,false,0.5,0.99,0.9,0.75,"",true);

  plotMuTau("LFVvsSMH_HiggsPt_TIGHT","histoHiggs_MUTAU_selectedTight","histoHiggs_MUTAU_selected","Higgs p_{T} [GeV]","a.u.",0,1000,1,false,0.5,0.99,0.9,0.75,"",true);
  plotMuTau("LFVvsSMH_HiggsPt_TIGHT","histoHiggs_MUTAU_selectedTight","histoHiggs_MUTAU_selected","Higgs p_{T} [GeV]","#sigma x Br [pb] / 5 GeV",0,1000,1,true,0.5,0.99,0.9,0.75,"");
  plotMuTau("LFVvsSMH_HiggsPt_TIGHT_status2","histoHiggs_MUTAU_selectedTight_2","histoHiggs_MUTAU_selected_2","Higgs p_{T} [GeV]","#sigma x Br [pb] / 5 GeV",0,1000,1,true,0.5,0.99,0.9,0.75,"");
  plotMuTau("LFVvsSMH_HiggsPt_TIGHT_status2","histoHiggs_MUTAU_selectedTight_2","histoHiggs_MUTAU_selected_2","Higgs p_{T} [GeV]","a.u.",0,1000,1,true,0.5,0.99,0.9,0.75,"",true);


  plotMuTau("LFVvsSMH_MuonPt_TIGHT","histoMuon_MUTAU_selectedTight","histoMuon_MUTAU_selected","Muon p_{T} [GeV]","#sigma x Br [pb] / 5 GeV",0,200,1,false,0.5,0.99,0.9,0.75,"");
  plotMuTau("LFVvsSMH_TauPt_TIGHT","histoTau_MUTAU_selectedTight","histoTau_MUTAU_selected","Tau p_{T} [GeV]","#sigma x Br [pb] / 5 GeV",0,200,1,false,0.5,0.99,0.9,0.75,"");
  plotMuTau("LFVvsSMH_MuonTauPt_TIGHT","histoMuon_MUTAU_selectedTight","histoTau2_MUTAU_selected","Muon p_{T} [GeV]","#sigma x Br [pb] / 5 GeV",0,200,1,false,0.5,0.99,0.9,0.75,"");
  plotMuTau("LFVvsSMH_MuonTauPt_TIGHT","histoMuon_MUTAU_selectedTight","histoTau2_MUTAU_selected","Muon p_{T} [GeV]","a.u.",0,200,1,false,0.5,0.99,0.9,0.75,"",true);
  plotMuTau("LFVvsSMH_TauPt_TIGHT","histoTau_MUTAU_selectedTight","histoTau_MUTAU_selected","Tau p_{T} [GeV]","#sigma x Br [pb] / 5 GeV",0,200,1,false,0.5,0.99,0.9,0.75,"",true);
  plotMuTau("LFVvsSMH_MuonPt_TIGHT","histoMuon_MUTAU_selectedTight","histoMuon_MUTAU_selected","Muon p_{T} [GeV]","a.u.",0,200,1,false,0.5,0.99,0.9,0.75,"",true);


  plotMuTau("LFVvsSMH_HiggsPt_SELECTED","histoHiggs_MUTAU_selected","histoHiggs_MUTAU_selected","Higgs p_{T} [GeV]","a.u.",0,200,1,false,0.5,0.99,0.9,0.75,"",true);
  plotMuTau("LFVvsSMH_HiggsPt_SELECTED","histoHiggs_MUTAU_selected","histoHiggs_MUTAU_selected","Higgs p_{T} [GeV]","#sigma x Br [pb] / 5 GeV",0,200,1,false,0.5,0.99,0.9,0.75,"");
  plotMuTau("LFVvsSMH_HiggsPt_SELECTED_status2","histoHiggs_MUTAU_selected_2","histoHiggs_MUTAU_selected_2","Higgs p_{T} [GeV]","#sigma x Br [pb] / 5 GeV",0,200,1,false,0.5,0.99,0.9,0.75,"");
  plotMuTau("LFVvsSMH_HiggsPt_SELECTED_status2","histoHiggs_MUTAU_selected_2","histoHiggs_MUTAU_selected_2","Higgs p_{T} [GeV]","a.u.",0,200,1,false,0.5,0.99,0.9,0.75,"",true);

  plotMuTau("LFVvsSMH_HiggsPt_SELECTED","histoHiggs_MUTAU_selected","histoHiggs_MUTAU_selected","Higgs p_{T} [GeV]","a.u.",0,1000,1,false,0.5,0.99,0.9,0.75,"",true);
  plotMuTau("LFVvsSMH_HiggsPt_SELECTED","histoHiggs_MUTAU_selected","histoHiggs_MUTAU_selected","Higgs p_{T} [GeV]","#sigma x Br [pb] / 5 GeV",0,1000,1,true,0.5,0.99,0.9,0.75,"");
  plotMuTau("LFVvsSMH_HiggsPt_SELECTED_status2","histoHiggs_MUTAU_selected_2","histoHiggs_MUTAU_selected_2","Higgs p_{T} [GeV]","#sigma x Br [pb] / 5 GeV",0,1000,1,true,0.5,0.99,0.9,0.75,"");
  plotMuTau("LFVvsSMH_HiggsPt_SELECTED_status2","histoHiggs_MUTAU_selected_2","histoHiggs_MUTAU_selected_2","Higgs p_{T} [GeV]","a.u.",0,1000,1,true,0.5,0.99,0.9,0.75,"",true);


  plotMuTau("LFVvsSMH_MuonPt_SELECTED","histoMuon_MUTAU_selected","histoMuon_MUTAU_selected","Muon p_{T} [GeV]","#sigma x Br [pb] / 5 GeV",0,200,1,false,0.5,0.99,0.9,0.75,"");
  plotMuTau("LFVvsSMH_TauPt_SELECTED","histoTau_MUTAU_selected","histoTau_MUTAU_selected","Tau p_{T} [GeV]","#sigma x Br [pb] / 5 GeV",0,200,1,false,0.5,0.99,0.9,0.75,"");
  plotMuTau("LFVvsSMH_MuonTauPt_SELECTED","histoMuon_MUTAU_selected","histoTau2_MUTAU_selected","Muon p_{T} [GeV]","#sigma x Br [pb] / 5 GeV",0,200,1,false,0.5,0.99,0.9,0.75,"");
  plotMuTau("LFVvsSMH_MuonTauPt_SELECTED","histoMuon_MUTAU_selected","histoTau2_MUTAU_selected","Muon p_{T} [GeV]","a.u.",0,200,1,false,0.5,0.99,0.9,0.75,"",true);
  plotMuTau("LFVvsSMH_TauPt_SELECTED","histoTau_MUTAU_selected","histoTau_MUTAU_selected","Tau p_{T} [GeV]","#sigma x Br [pb] / 5 GeV",0,200,1,false,0.5,0.99,0.9,0.75,"",true);
  plotMuTau("LFVvsSMH_MuonPt_SELECTED","histoMuon_MUTAU_selected","histoMuon_MUTAU_selected","Muon p_{T} [GeV]","a.u.",0,200,1,false,0.5,0.99,0.9,0.75,"",true);

  plotMuTau("LFVvsSMH_HiggsPt_pythia8_st62","histoHiggsPt","histoHiggs2Pt","Higgs p_{T} [GeV]","#sigma x Br [pb] / 5 GeV",0,100,1,false,0.5,0.99,0.9,0.75,"");
  plotMuTau("LFVvsSMH_HiggsPt_pythia8_st62","histoHiggsPt","histoHiggs2Pt","Higgs p_{T} [GeV]","#sigma x Br [pb] / 50 GeV",0,1000,10,true,0.5,0.99,0.9,0.75,"");



  plotMuTau("LFVvsSMH_HiggsPt_pythia8_st44","histoHiggs2Pt","histoHiggsPt","Higgs p_{T} [GeV]","#sigma x Br [pb] / 5 GeV",0,100,1,false,0.5,0.99,0.9,0.75,"");
  plotMuTau("LFVvsSMH_HiggsPt_pythia8_st62","histoHiggsPt","histoHiggsPt","Higgs p_{T} [GeV]","a.u. / 5 GeV",0,100,1,false,0.5,0.99,0.9,0.75,"");
  plotMuTau("LFVvsSMH_HiggsPt_pythia8_st44","histoHiggs2Pt","histoHiggsPt","Higgs p_{T} [GeV]","#sigma x Br [pb] / 5 GeV",0,1000,10,true,0.5,0.99,0.9,0.75,"");
  plotMuTau("LFVvsSMH_HiggsPt_pythia8_st62","histoHiggsPt","histoHiggsPt","Higgs p_{T} [GeV]","a.u. / 5 GeV",0,1000,10,true,0.5,0.99,0.9,0.75,"");
  plotMuTau("LFVvsSMH_HiggsMass_pythia8_st44","histoHiggs2Mass","histoHiggsMass","Higgs Mass [GeV]","#sigma x Br [pb] / 0.01 GeV",124.5,125.5,1,true,0.6,0.99,0.99,0.75,"");
  plotMuTau("LFVvsSMH_HiggsMass_pythia8_st62","histoHiggsMass","histoHiggsMass","Higgs Mass [GeV]","#sigma x Br [pb] /  0.01 GeV",124.5,125.5,1,true,0.6,0.99,0.99,0.75,"");
  plotMuTau("LFVvsSMH_HiggsEta_pythia8_st44","histoHiggs2Eta","histoHiggsEta","Higgs #eta","#sigma x Br [pb] / 0.1",-5,5,1,false,0.4,0.99,0.8,0.75,"");
  plotMuTau("LFVvsSMH_HiggsEta_pythia8_st62","histoHiggsEta","histoHiggsEta","Higgs #eta","a.u. / 0.1",-5,5,1,false,0.4,0.99,0.8,0.75,"");


  plotMuTau("LFVvsSMH_Tau_mutauhad","histoFinalTau_MUTAU","histoFinalTau_MUTAU","#tau p_{T} [GeV]","#sigma x Br [pb] / 5 GeV",0,200,5,true,0.6,0.9,0.9,0.75,"#mu #tau_{had}");
  plotMuTau("LFVvsSMH_DeltaTauMuon_mutauhad","histoDeltaTauMuon_MUTAU","histoDeltaTauMuon_MUTAU","#Delta #phi (#mu,#tau)","#sigma x Br [pb] / 0.7",0,3.15,1,true,0.3,0.9,0.6,0.75,"#mu #tau_{had}");
  plotMuTau("LFVvsSMH_DeltaElectronMuon_mutauele","histoDeltaElectronMuon_MUELE","histoDeltaElectronMuon_MUELE","#Delta #phi (#mu,e)","#sigma x Br [pb] / 0.7",0,3.15,1,true,0.3,0.9,0.6,0.75,"#mu #tau_{e}");
  plotMuTau("LFVvsSMH_DeltaNeutrinoMuon_mutauhad","histoDeltaNeutrinoMuon_MUTAU","histoDeltaNeutrinoMuon_MUTAU","#Delta #phi (#mu,#Sigma#nu)","#sigma x Br [pb] / 0.7",0,3.15,1,true,0.3,0.9,0.6,0.75,"#mu #tau_{had}");
  plotMuTau("LFVvsSMH_DeltaNeutrinoMuon_mutauele","histoDeltaNeutrinoMuon_MUELE","histoDeltaNeutrinoMuon_MUELE","#Delta #phi (#mu,#Sigma#nu)","#sigma x Br [pb] / 0.7",0,3.15,1,true,0.3,0.9,0.6,0.75,"#mu #tau_{e}");
  plotMuTau("LFVvsSMH_DeltaNeutrinoTau_mutauhad","histoDeltaNeutrinoTau_MUTAU","histoDeltaNeutrinoTau_MUTAU","#Delta #phi (#tau,#Sigma#nu)","#sigma x Br [pb] / 0.7",0,3.15,1,true,0.3,0.9,0.6,0.75,"#mu #tau_{had}");
  plotMuTau("LFVvsSMH_DeltaNeutrinoElectron_mutauele","histoDeltaNeutrinoElectron_MUELE","histoDeltaNeutrinoElectron_MUELE","#Delta #phi (e,#Sigma#nu)","#sigma x Br [pb] / 0.7",0,3.15,1,true,0.3,0.9,0.6,0.75,"#mu #tau_{e}");
  plotMuTau("LFVvsSMH_Muon_mutauele","histoFinalMuon_MUELE","histoFinalMuon_MUELE","#mu p_{T} [GeV]","#sigma x Br [pb] / 5 GeV",0,200,5,true,0.6,0.9,0.9,0.75,"#mu #tau_{e}");
  plotMuTau("LFVvsSMH_Muon_mutauhad","histoFinalMuon_MUTAU","histoFinalMuon_MUTAU","#mu p_{T} [GeV]","#sigma x Br [pb] / 5 GeV",0,200,5,true,0.6,0.9,0.9,0.75,"#mu #tau_{had}");
  plotMuTau("LFVvsSMH_Tau_mutauhad","histoFinalTau_MUTAU","histoFinalTau_MUTAU","#tau p_{T} [GeV]","#sigma x Br [pb] / 5 GeV",0,200,5,true,0.6,0.9,0.9,0.75,"#mu #tau_{had}");
  plotMuTau("LFVvsSMH_Electron_mutauele","histoFinalElectron_MUELE","histoFinalElectron_MUELE","e p_{T} [GeV]","#sigma x Br [pb] / 5 GeV",0,200,5,true,0.6,0.9,0.9,0.75,"#mu #tau_{e}");

}

