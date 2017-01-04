object fCalculator: TfCalculator
  Left = 779
  Top = 189
  Width = 766
  Height = 338
  Caption = 'Calculator'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object eFirstNumber: TEdit
    Left = 8
    Top = 24
    Width = 625
    Height = 21
    TabOrder = 0
  end
  object eSecondNumber: TEdit
    Left = 8
    Top = 120
    Width = 625
    Height = 21
    TabOrder = 1
  end
  object eResult: TEdit
    Left = 8
    Top = 216
    Width = 625
    Height = 21
    TabOrder = 2
  end
  object btnAdd: TButton
    Left = 656
    Top = 24
    Width = 83
    Height = 33
    Caption = 'ADD'
    TabOrder = 3
    OnClick = btnAddClick
  end
  object btnSubstract: TButton
    Left = 656
    Top = 72
    Width = 83
    Height = 33
    Caption = 'SUBSTRACT'
    TabOrder = 4
  end
  object btbMultiply: TButton
    Left = 656
    Top = 120
    Width = 83
    Height = 33
    Caption = 'MULTIPLY'
    TabOrder = 5
  end
  object btnDivide: TButton
    Left = 656
    Top = 168
    Width = 83
    Height = 33
    Caption = 'DIVIDE'
    TabOrder = 6
  end
  object btnInverse: TButton
    Left = 656
    Top = 216
    Width = 83
    Height = 33
    Caption = 'INVERSE'
    TabOrder = 7
  end
  object btnSquareRoot: TButton
    Left = 656
    Top = 264
    Width = 83
    Height = 33
    Caption = 'SQUARE ROOT'
    TabOrder = 8
  end
  object btnExit: TButton
    Left = 536
    Top = 264
    Width = 75
    Height = 25
    Caption = 'EXIT'
    TabOrder = 9
    OnClick = btnExitClick
  end
end
