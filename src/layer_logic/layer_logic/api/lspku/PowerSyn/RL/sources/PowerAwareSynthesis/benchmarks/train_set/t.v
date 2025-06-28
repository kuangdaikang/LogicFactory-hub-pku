// Benchmark "C17.iscas" written by ABC on Fri Feb 25 15:12:39 2022

module t  ( 
    \1GAT(0) , \2GAT(1) , \3GAT(2) , \6GAT(3) , \7GAT(4) ,
    \22GAT(10) , \23GAT(9)   );
  input  \1GAT(0) , \2GAT(1) , \3GAT(2) , \6GAT(3) , \7GAT(4) ;
  output \22GAT(10) , \23GAT(9) ;
  wire new_n8_, new_n9_, new_n10_, new_n12_;
  assign new_n8_ = \3GAT(2)  & \6GAT(3) ;
  assign new_n9_ = \2GAT(1)  & ~new_n8_;
  assign new_n10_ = \1GAT(0)  & \3GAT(2) ;
  assign \22GAT(10)  = new_n9_ | new_n10_;
  assign new_n12_ = ~\2GAT(1)  & ~\7GAT(4) ;
  assign \23GAT(9)  = ~new_n8_ & ~new_n12_;
endmodule


