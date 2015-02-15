void plotMuTau(TString plotName="test", TString name="histoDeltaTauMuon_MUTAU",TString name2="histoDeltaTauMuon_MUTAU",  TString Xaxis="#Delta #phi (#mu,#tau)", TString Yaxis="#sigma [pb] / 0.7", double xmin=0, double xmax=3.15, int rebinning=1, bool setLogY=true, double legx1=0.3, double legy1=0.90, double legx2=0.6, double legy2=0.75, TString label="#mu #tau_{had}",bool normalize=false){

  gROOT->LoadMacro("tdrstyle.C");
  setTDRStyle();

        gROOT->LoadMacro("CMS_lumi.C");
        writeExtraText = true;
  	extraText  = "Simulation";  // default extra text is "Preliminary"
  	lumi_8TeV  = ""; // default is "19.7 fb^{-1}"
        int iPeriod = 2;
        // second parameter in example_plot is iPos, which drives the position of the CMS logo in the plot
        int iPos=11;



 // Get Plots

        TFile *_file1= new TFile("htaumu_mutau.root");
	TH1F *hHTauMu=_file1->Get(name); hHTauMu->SetName("HTauMu");

        TFile *_file0= new TFile("htautau_mutau.root");
        TH1F *hH2Tau=_file0->Get(name2); hH2Tau->SetName("H2Tau");

// Normalize to 

	double events=19.520*0.1;


// Colors

        hH2Tau->SetLineColor(kPink+10); hH2Tau->SetLineWidth(2);
        hHTauMu->SetLineColor(kAzure); hHTauMu->SetLineWidth(2);

 // Rebin

	hH2Tau->Rebin(rebinning);
        hHTauMu->Rebin(rebinning);

	hH2Tau->Scale(events/955835);
	hHTauMu->Scale(events/161820);

	if(normalize) {
		hH2Tau->Scale(1./hH2Tau->Integral());
                hHTauMu->Scale(1./hHTauMu->Integral());
	}


// Labelling

	hH2Tau->SetXTitle(Xaxis);
        hH2Tau->SetYTitle(Yaxis);
        hHTauMu->SetXTitle(Xaxis);
        hHTauMu->SetYTitle(Yaxis);

	hH2Tau->GetXaxis()->SetRangeUser(xmin,xmax);

	double scaleMax=1.2;
	if (setLogY) scaleMax=2;

        if(hHTauMu->GetMaximum()>hH2Tau->GetMaximum())  hH2Tau->SetMaximum(hHTauMu->GetMaximum()*scaleMax);
	

	hH2Tau->GetXaxis()->SetLabelFont(42);
	hH2Tau->GetXaxis()->SetTitleSize(0.05);
	hH2Tau->GetXaxis()->SetTitleFont(42);
	hH2Tau->GetYaxis()->SetLabelFont(42);
	hH2Tau->GetYaxis()->SetTitleSize(0.05);
	hH2Tau->GetYaxis()->SetTitleOffset(1.2);
	hH2Tau->GetYaxis()->SetTitleFont(42);


// PLOT


	TCanvas *c1 = new TCanvas("canvas_"+name);   
	TPad *Pad1= new TPad("pad1","",0,0.,1,1); Pad1->Draw(); Pad1->cd();;
   	Pad1->SetLeftMargin(0.15);
   	Pad1->SetRightMargin(0.05);
   	Pad1->SetTopMargin(0.05);
   	Pad1->SetBottomMargin(0.15);
	Pad1->SetLogy(setLogY);

	hH2Tau->Draw("hist");
	hHTauMu->Draw("sames,hist");

   	TLegend *leg = new TLegend(legx1,legy1,legx2,legy2,NULL,"brNDC");
   	leg->SetFillColor(0);
   	leg->SetBorderSize(0);
   	leg->SetFillStyle(0);
   	TLegendEntry *entry;
        entry=leg->AddEntry("NULL",label,"");
   	entry=leg->AddEntry(hH2Tau,"h#rightarrow#tau^{+}#tau^{-} ","l");
        entry=leg->AddEntry(hHTauMu,"h#rightarrow #tau #mu","l");
   	leg->Draw();

   	//cmsPrelim();
        CMS_lumi(Pad1, iPeriod, iPos );

	if(normalize) plotName=plotName+"_norm";
	if(setLogY)   plotName=plotName+"_log";

       		c1->SaveAs(plotName+".png");
       		c1->SaveAs(plotName+".pdf");

}



void cmsPrelim(){  TLatex latex;
  latex.SetNDC();
  latex.SetTextSize(0.04);

  latex.SetTextAlign(31); // align right
  latex.DrawLatex(0.9,0.96,Form("#sqrt{s} = 8 TeV"));

  latex.SetTextAlign(11); // align left
  latex.DrawLatex(0.25,0.96,"CMS simulation preliminary");
}


