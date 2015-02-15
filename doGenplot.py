'''
Makes Gen Level LFV plots
Author: Aaron Levine
'''
from sys import argv, stdout, stderr
import ROOT
import sys

#ntupleStr = argv[1]
var = argv[1]
ntupleStr ="VBF"
#var ='higgsPt'
if "GGF" in ntupleStr:
	channel = "GGF"
if "VBF" in ntupleStr:
	channel = "VBF"
if "VH" in ntupleStr:
	channel = "VH"
if "mu" in var:
	cutStr = "((pdgId==13 && motherPdgId==15)||(pdgId==-13 && motherPdgId==-15))&&(status==1)" #muon from tau
if "ele" in var:
	cutStr = "(abs(pdgId)==11 && motherPdgId==25 && status == 1)" #ele from higgs
if "tau" in var: 
	cutStr = "(abs(pdgId)==15 && motherPdgId==25 && status == 2)" #tau from Higgs
if "higgs" in var:
	cutStr = "(pdgId==25&&status==62)" #higgs from ggf/vbf/vh
if "Pt" in var:
	varKin = "pt"
#	binning = [20,0,100]
	binning = [25,0,500]
if "Eta" in var:
	varKin = "eta"
	binning = [48,-6,6]
if "Phi" in var:
	varKin = "phi"
	binning = [21,-3.5,3.5]
saveStr = "GenLevelFiles_Feb10/GEN_HToeTau_"+channel+"_"+var

#ntuple_file13 = ROOT.TFile(ntupleStr+"_13TeV.root")
#ntuple_file8 = ROOT.TFile(ntupleStr+"_8TeV.root")
ntuple_file13 = ROOT.TFile("VBFHetau13TeV.root")
ntuple_file8 = ROOT.TFile("VBFHetau8TeV.root")
ntuple_spot = 'BasicGenInfo/Ntuple'

ntuple13 = ntuple_file13.Get(ntuple_spot)
ntuple8 = ntuple_file8.Get(ntuple_spot)

ROOT.gROOT.LoadMacro("tdrstyle.C")
ROOT.setTDRStyle()
ROOT.gROOT.SetStyle("Plain")
ROOT.gROOT.SetBatch(True)
ROOT.gStyle.SetOptStat(0)

tex = ROOT.TLatex()
tex.SetTextSize(0.07)
tex.SetTextAlign(11)
tex.SetNDC(True)

canvas = ROOT.TCanvas("asdf", "adsf", 800, 800)
canvas.SetLogy()
drawStr = "%s >>htemp(%s)" % (varKin, ", ".join(str(x) for x in binning))

ntuple13.Draw(drawStr, cutStr, "goff")
histo13 = ROOT.gDirectory.Get("htemp").Clone()
histo13.GetXaxis().SetTitle(var)

ntuple8.Draw(drawStr, cutStr, "goff")
histo8 = ROOT.gDirectory.Get("htemp").Clone()
histo8.GetXaxis().SetTitle(var)

max13 = histo13.GetMaximum()
max8 = histo8.GetMaximum()

maxHisto = max(max13,max8)

histo13.SetLineColor(ROOT.EColor.kBlue)
histo13.Draw("histE1")
histo13.GetYaxis().SetRangeUser(0,1.1*maxHisto)
histo13.SetTitle("13 TeV vs 8 TeV eTau"+channel)

histo8.SetLineColor(ROOT.EColor.kRed)
histo8.Draw("sameshistE1")



legend = ROOT.TLegend(0.65,0.55,0.85,0.65,'','brNDC')
legend.SetFillColor(0)
legend.SetBorderSize(0)
legend.SetTextSize(0.03)

legend.AddEntry(histo13,"13 TeV")
legend.AddEntry(histo8,"8 TeV")

legend.Draw("sames")

canvas.SaveAs(saveStr+".png")

