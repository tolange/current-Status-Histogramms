#include "TFile.h"
#include "TH1D.h"
#include "TCanvas.h"
#include "TPaveStats.h"
#include "THStack.h"
#include "TLegend.h"

void likelihoodtesthistos(){
  TFile *f = new TFile("backgroundtest.root","READ");

  // all chi2 histos:

  THStack *allchi2 = new THStack("allchi2","chi2 for all fit-hypothesis");
  TH1D *chi2MHP1P2 = (TH1D*) f->Get("h_FitFinalChi2h");
  chi2MHP1P2->SetLineColor(kRed);
  chi2MHP1P2->SetLineStyle(1);
  allchi2->Add(chi2MHP1P2);
  TH1D *chi2MZP1P1 = (TH1D*) f->Get("h_FitFinalChi2b");
  chi2MZP1P1->SetLineColor(kBlue);
  chi2MZP1P1->SetLineStyle(3);
  allchi2->Add(chi2MZP1P1);
  TH1D *chi2MHP1P1 = (TH1D*) f->Get("h_FitFinalChi2halt");
  chi2MHP1P1->SetLineColor(kBlue);
  chi2MHP1P1->SetLineStyle(1);
  allchi2->Add(chi2MHP1P1);
  TH1D *chi2MZP1P2 = (TH1D*) f->Get("h_FitFinalChi2balt");
  chi2MZP1P2->SetLineColor(kRed);
  chi2MZP1P2->SetLineStyle(3);
  allchi2->Add(chi2MZP1P2);
  TH1D *chi2MHP2P1 = (TH1D*) f->Get("h_FitFinalChi2halt2");
  chi2MHP2P1->SetLineColor(kBlack);
  chi2MHP2P1->SetLineStyle(1);
  allchi2->Add(chi2MHP2P1);
  TH1D *chi2MZP2P1 = (TH1D*) f->Get("h_FitFinalChi2balt2");
  chi2MZP2P1->SetLineColor(kBlack);
  chi2MZP2P1->SetLineStyle(3);
  allchi2->Add(chi2MZP2P1);
  TH1D *chi2MHP2P2 = (TH1D*) f->Get("h_FitFinalChi2halt3");
  chi2MHP2P2->SetLineColor(kViolet);
  chi2MHP2P2->SetLineStyle(1);
  allchi2->Add(chi2MHP2P2);
  TH1D *chi2MZP2P2 = (TH1D*) f->Get("h_FitFinalChi2balt3");
  chi2MZP2P2->SetLineColor(kViolet);
  chi2MZP2P2->SetLineStyle(3);
  allchi2->Add(chi2MZP2P2);

  TCanvas *c_allchi2=new TCanvas("c_allchi2","chi2 for all fit-hypothesis",1000,1000);
  allchi2->Draw("nostack");
  allchi2->GetXaxis()->SetRangeUser(0,6);
  allchi2->GetYaxis()->SetTitleOffset(1.5);
  allchi2->GetXaxis()->SetTitle("#chi^2");
  allchi2->GetYaxis()->SetTitle("counts/0.125");
  allchi2->Draw("nostack");
  //----------------------------------------------------------------
  //all chi2 likelihood histos:

  THStack *allchi2likelihood = new THStack("allchi2likelihood","chi2likelihood for all fit-hypothesis");
  TH1D *chi2likelihoodMHP1P2 = (TH1D*) f->Get("h_FitFinalChi2hlikelihood");
  chi2likelihoodMHP1P2->SetLineColor(kRed);
  chi2likelihoodMHP1P2->SetLineStyle(1);
  allchi2likelihood->Add(chi2likelihoodMHP1P2);
  TH1D *chi2likelihoodMZP1P1 = (TH1D*) f->Get("h_FitFinalChi2blikelihood");
  chi2likelihoodMZP1P1->SetLineColor(kBlue);
  chi2likelihoodMZP1P1->SetLineStyle(3);
  allchi2likelihood->Add(chi2likelihoodMZP1P1);
  TH1D *chi2likelihoodMHP1P1 = (TH1D*) f->Get("h_FitFinalChi2haltlikelihood");
  chi2likelihoodMHP1P1->SetLineColor(kBlue);
  chi2likelihoodMHP1P1->SetLineStyle(1);
  allchi2likelihood->Add(chi2likelihoodMHP1P1);
  TH1D *chi2likelihoodMZP1P2 = (TH1D*) f->Get("h_FitFinalChi2baltlikelihood");
  chi2likelihoodMZP1P2->SetLineColor(kRed);
  chi2likelihoodMZP1P2->SetLineStyle(3);
  allchi2likelihood->Add(chi2likelihoodMZP1P2);
  TH1D *chi2likelihoodMHP2P1 = (TH1D*) f->Get("h_FitFinalChi2halt2likelihood");
  chi2likelihoodMHP2P1->SetLineColor(kBlack);
  chi2likelihoodMHP2P1->SetLineStyle(1);
  allchi2likelihood->Add(chi2likelihoodMHP2P1);
  TH1D *chi2likelihoodMZP2P1 = (TH1D*) f->Get("h_FitFinalChi2balt2likelihood");
  chi2likelihoodMZP2P1->SetLineColor(kBlack);
  chi2likelihoodMZP2P1->SetLineStyle(3);
  allchi2likelihood->Add(chi2likelihoodMZP2P1);
  TH1D *chi2likelihoodMHP2P2 = (TH1D*) f->Get("h_FitFinalChi2halt3likelihood");
  chi2likelihoodMHP2P2->SetLineColor(kViolet);
  chi2likelihoodMHP2P2->SetLineStyle(1);
  allchi2likelihood->Add(chi2likelihoodMHP2P2);
  TH1D *chi2likelihoodMZP2P2 = (TH1D*) f->Get("h_FitFinalChi2balt3likelihood");
  chi2likelihoodMZP2P2->SetLineColor(kViolet);
  chi2likelihoodMZP2P2->SetLineStyle(3);
  allchi2likelihood->Add(chi2likelihoodMZP2P2);

  TCanvas *c_allchi2likelihood=new TCanvas("c_allchi2likelihood","chi2likelihood for all fit-hypothesis",1000,1000);
  allchi2likelihood->Draw("nostack");
  allchi2likelihood->GetYaxis()->SetTitleOffset(2);
  allchi2likelihood->GetXaxis()->SetTitle("#chi^2");
  allchi2likelihood->GetYaxis()->SetTitle("counts/0.125");
  allchi2likelihood->Draw("nostack");

  //------------------------------------------------------------------------------------
  // all L-functions
  THStack *allL = new THStack("allL","L for all fit-hypothesis");
    TH1D *LMHP1P2 = (TH1D*) f->Get("h_Likelihoodh");
    LMHP1P2->SetLineColor(kRed);
    LMHP1P2->SetLineStyle(1);
    allL->Add(LMHP1P2);
    TH1D *LMZP1P1 = (TH1D*) f->Get("h_Likelihoodb");
    LMZP1P1->SetLineColor(kBlue);
    LMZP1P1->SetLineStyle(3);
    allL->Add(LMZP1P1);
    TH1D *LMHP1P1 = (TH1D*) f->Get("h_Likelihoodhalt");
    LMHP1P1->SetLineColor(kBlue);
    LMHP1P1->SetLineStyle(1);
    allL->Add(LMHP1P1);
    TH1D *LMZP1P2 = (TH1D*) f->Get("h_Likelihoodbalt");
    LMZP1P2->SetLineColor(kRed);
    LMZP1P2->SetLineStyle(3);
    allL->Add(LMZP1P2);
    TH1D *LMHP2P1 = (TH1D*) f->Get("h_Likelihoodhalt2");
    LMHP2P1->SetLineColor(kBlack);
    LMHP2P1->SetLineStyle(1);
    allL->Add(LMHP2P1);
    TH1D *LMZP2P1 = (TH1D*) f->Get("h_Likelihoodbalt2");
    LMZP2P1->SetLineColor(kBlack);
    LMZP2P1->SetLineStyle(3);
    allL->Add(LMZP2P1);
    TH1D *LMHP2P2 = (TH1D*) f->Get("h_Likelihoodhalt3");
    LMHP2P2->SetLineColor(kViolet);
    LMHP2P2->SetLineStyle(1);
    allL->Add(LMHP2P2);
    TH1D *LMZP2P2 = (TH1D*) f->Get("h_Likelihoodbalt3");
    LMZP2P2->SetLineColor(kViolet);
    LMZP2P2->SetLineStyle(3);
    allL->Add(LMZP2P2);

    TCanvas *c_allL=new TCanvas("c_allL","L for all fit-hypothesis",1000,1000);
    allL->Draw("nostack");
    allL->GetYaxis()->SetTitleOffset(2);
    allL->GetXaxis()->SetTitle("L");
    allL->GetYaxis()->SetTitle("counts/(5*10^-5)");
    allL->Draw("nostack");

    //------------------------------------------------------------------------------------
      // all LLikelihood-functions
      THStack *allLlikelihood = new THStack("allLlikelihood","Llikelihood for all fit-hypothesis");
        TH1D *LlikelihoodMHP1P2 = (TH1D*) f->Get("h_Likelihoodhlikelihood");
        LlikelihoodMHP1P2->SetLineColor(kRed);
        LlikelihoodMHP1P2->SetLineStyle(1);
        allLlikelihood->Add(LlikelihoodMHP1P2);
        TH1D *LlikelihoodMZP1P1 = (TH1D*) f->Get("h_Likelihoodblikelihood");
        LlikelihoodMZP1P1->SetLineColor(kBlue);
        LlikelihoodMZP1P1->SetLineStyle(3);
        allLlikelihood->Add(LlikelihoodMZP1P1);
        TH1D *LlikelihoodMHP1P1 = (TH1D*) f->Get("h_Likelihoodhaltlikelihood");
        LlikelihoodMHP1P1->SetLineColor(kBlue);
        LlikelihoodMHP1P1->SetLineStyle(1);
        allLlikelihood->Add(LlikelihoodMHP1P1);
        TH1D *LlikelihoodMZP1P2 = (TH1D*) f->Get("h_Likelihoodbaltlikelihood");
        LlikelihoodMZP1P2->SetLineColor(kRed);
        LlikelihoodMZP1P2->SetLineStyle(3);
        allLlikelihood->Add(LlikelihoodMZP1P2);
        TH1D *LlikelihoodMHP2P1 = (TH1D*) f->Get("h_Likelihoodhalt2likelihood");
        LlikelihoodMHP2P1->SetLineColor(kBlack);
        LlikelihoodMHP2P1->SetLineStyle(1);
        allLlikelihood->Add(LlikelihoodMHP2P1);
        TH1D *LlikelihoodMZP2P1 = (TH1D*) f->Get("h_Likelihoodbalt2likelihood");
        LlikelihoodMZP2P1->SetLineColor(kBlack);
        LlikelihoodMZP2P1->SetLineStyle(3);
        allLlikelihood->Add(LlikelihoodMZP2P1);
        TH1D *LlikelihoodMHP2P2 = (TH1D*) f->Get("h_Likelihoodhalt3likelihood");
        LlikelihoodMHP2P2->SetLineColor(kViolet);
        LlikelihoodMHP2P2->SetLineStyle(1);
        allLlikelihood->Add(LlikelihoodMHP2P2);
        TH1D *LlikelihoodMZP2P2 = (TH1D*) f->Get("h_Likelihoodbalt3likelihood");
        LlikelihoodMZP2P2->SetLineColor(kViolet);
        LlikelihoodMZP2P2->SetLineStyle(3);
        allLlikelihood->Add(LlikelihoodMZP2P2);

        TCanvas *c_allLlikelihood=new TCanvas("c_allLlikelihood","Llikelihood for all fit-hypothesis",1000,1000);
        allLlikelihood->Draw("nostack");
        allLlikelihood->GetYaxis()->SetTitleOffset(2);
        allLlikelihood->GetXaxis()->SetTitle("L");
        allLlikelihood->GetYaxis()->SetTitle("counts/(5*10^-5)");
        allLlikelihood->Draw("nostack");



























}
