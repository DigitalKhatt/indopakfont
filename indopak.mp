%%  
 % This file is part of DigitalKhatt IndoPak Font which is licensed under the SIL Open Font License, Version 1.1.
 % Go to https://github.com/DigitalKhatt/indopakfont/blob/main/LICENSE for full license details.
%%

nametable.familyName := "DigitalKhatt IndoPak";
nametable.copyright := "Copyright (c) 2024 Amine Anane, Copyright © 2024 Tarteel Inc.";
lineheight := 135;
penwidth := 135;
joinvector := ljoinvector := rjoinvector := (20,lineheight); 
nuqta := 1.4penwidth;
noondepth := 200;
noonexpadepth := 200;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
pair ljoinvectorii;ljoinvectorii := (0,4/5lineheight); 
lresiduii := 1lineheight;
ltensionii := 1.2;
secondarydef p leftjoinii q =
   hide(
    setdef(x.lft.offset,nuqta + 50);
    setdef(y.lft.offset,0);
    setdef(x.lft.ratio.2 ,44);
    setdef(x.lft.ratio.1.top ,11);
    setdef(y.lft.ratio.1.top ,30);
    setdef(x.lft.ratio.1.bot ,x.lft.ratio.1.top);
    setdef(y.lft.ratio.1.bot ,y.lft.ratio.1.top);

    tatweel_ :=  lefttatweel *nuqta;  

    if tatweel_ > 0 :
       z.lft.bot =  round(-(tatweel_ ,tatweel_ / leftVerticalRatio));    
    else:
       z.lft.bot =  round(-(tatweel_,if leftVerticalRatioNeg <> 0 : tatweel_ / leftVerticalRatioNeg else : 0 fi ));  
    fi   
    z.lft.top = z.lft.bot + ljoinvectorii;

    ratio1_ := (100 - x.lft.ratio.2)/100;;  
    first_ratio_bot_x_ := x.lft.ratio.1.bot/100;
    first_ratio_bot_y_ := y.lft.ratio.1.bot /100;
    first_ratio_top_x_ := x.lft.ratio.1.top/100;
    first_ratio_top_y_ := y.lft.ratio.1.top/100;

    hight.bot_ :=  ypart p - y.lft.bot;
    width.bot_ :=  -x.lft.bot +xpart p;
    hight.top_ :=  ypart q - y.lft.top;
    width.top_ :=  -x.lft.top +xpart q;
    
    z_l1 := p - (width.bot_ * first_ratio_bot_x_,hight.bot_* first_ratio_bot_y_);    
    z_l2 :=  (x.lft.bot + width.bot_  * ratio1_,y.lft.bot);  
    z_l3 :=  (x.lft.top + width.top_  * ratio1_,y.lft.top); 
    z_l4 :=  q - (width.top_  *first_ratio_top_x_,hight.top_ * first_ratio_top_y_);
    leftanchor = z.lft.bot;    
  )

  p  ..  controls  z_l1 and z_l2 ..  
  z.lft.bot .. tension atleast ltensionii ..
  (1/2[ z.lft.bot,z.lft.top] - (lresiduii,0)) .. tension atleast ltensionii  ..
  z.lft.top  .. controls z_l3  and z_l4 .. 
 q
enddef;