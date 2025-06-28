// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VADDER_H_
#define VERILATED_VADDER_H_  // guard

#include "verilated.h"

class Vadder__Syms;
class Vadder___024root;
class VerilatedVcdC;

// This class is the main interface to the Verilated model
class alignas(VL_CACHE_LINE_BYTES) Vadder VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    Vadder__Syms* const vlSymsp;

  public:

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(&a__05b0__05d,0,0);
    VL_IN8(&a__05b1__05d,0,0);
    VL_IN8(&a__05b2__05d,0,0);
    VL_IN8(&a__05b3__05d,0,0);
    VL_IN8(&a__05b4__05d,0,0);
    VL_IN8(&a__05b5__05d,0,0);
    VL_IN8(&a__05b6__05d,0,0);
    VL_IN8(&a__05b7__05d,0,0);
    VL_IN8(&a__05b8__05d,0,0);
    VL_IN8(&a__05b9__05d,0,0);
    VL_IN8(&a__05b10__05d,0,0);
    VL_IN8(&a__05b11__05d,0,0);
    VL_IN8(&a__05b12__05d,0,0);
    VL_IN8(&a__05b13__05d,0,0);
    VL_IN8(&a__05b14__05d,0,0);
    VL_IN8(&a__05b15__05d,0,0);
    VL_IN8(&a__05b16__05d,0,0);
    VL_IN8(&a__05b17__05d,0,0);
    VL_IN8(&a__05b18__05d,0,0);
    VL_IN8(&a__05b19__05d,0,0);
    VL_IN8(&a__05b20__05d,0,0);
    VL_IN8(&a__05b21__05d,0,0);
    VL_IN8(&a__05b22__05d,0,0);
    VL_IN8(&a__05b23__05d,0,0);
    VL_IN8(&a__05b24__05d,0,0);
    VL_IN8(&a__05b25__05d,0,0);
    VL_IN8(&a__05b26__05d,0,0);
    VL_IN8(&a__05b27__05d,0,0);
    VL_IN8(&a__05b28__05d,0,0);
    VL_IN8(&a__05b29__05d,0,0);
    VL_IN8(&a__05b30__05d,0,0);
    VL_IN8(&a__05b31__05d,0,0);
    VL_IN8(&a__05b32__05d,0,0);
    VL_IN8(&a__05b33__05d,0,0);
    VL_IN8(&a__05b34__05d,0,0);
    VL_IN8(&a__05b35__05d,0,0);
    VL_IN8(&a__05b36__05d,0,0);
    VL_IN8(&a__05b37__05d,0,0);
    VL_IN8(&a__05b38__05d,0,0);
    VL_IN8(&a__05b39__05d,0,0);
    VL_IN8(&a__05b40__05d,0,0);
    VL_IN8(&a__05b41__05d,0,0);
    VL_IN8(&a__05b42__05d,0,0);
    VL_IN8(&a__05b43__05d,0,0);
    VL_IN8(&a__05b44__05d,0,0);
    VL_IN8(&a__05b45__05d,0,0);
    VL_IN8(&a__05b46__05d,0,0);
    VL_IN8(&a__05b47__05d,0,0);
    VL_IN8(&a__05b48__05d,0,0);
    VL_IN8(&a__05b49__05d,0,0);
    VL_IN8(&a__05b50__05d,0,0);
    VL_IN8(&a__05b51__05d,0,0);
    VL_IN8(&a__05b52__05d,0,0);
    VL_IN8(&a__05b53__05d,0,0);
    VL_IN8(&a__05b54__05d,0,0);
    VL_IN8(&a__05b55__05d,0,0);
    VL_IN8(&a__05b56__05d,0,0);
    VL_IN8(&a__05b57__05d,0,0);
    VL_IN8(&a__05b58__05d,0,0);
    VL_IN8(&a__05b59__05d,0,0);
    VL_IN8(&a__05b60__05d,0,0);
    VL_IN8(&a__05b61__05d,0,0);
    VL_IN8(&a__05b62__05d,0,0);
    VL_IN8(&a__05b63__05d,0,0);
    VL_IN8(&a__05b64__05d,0,0);
    VL_IN8(&a__05b65__05d,0,0);
    VL_IN8(&a__05b66__05d,0,0);
    VL_IN8(&a__05b67__05d,0,0);
    VL_IN8(&a__05b68__05d,0,0);
    VL_IN8(&a__05b69__05d,0,0);
    VL_IN8(&a__05b70__05d,0,0);
    VL_IN8(&a__05b71__05d,0,0);
    VL_IN8(&a__05b72__05d,0,0);
    VL_IN8(&a__05b73__05d,0,0);
    VL_IN8(&a__05b74__05d,0,0);
    VL_IN8(&a__05b75__05d,0,0);
    VL_IN8(&a__05b76__05d,0,0);
    VL_IN8(&a__05b77__05d,0,0);
    VL_IN8(&a__05b78__05d,0,0);
    VL_IN8(&a__05b79__05d,0,0);
    VL_IN8(&a__05b80__05d,0,0);
    VL_IN8(&a__05b81__05d,0,0);
    VL_IN8(&a__05b82__05d,0,0);
    VL_IN8(&a__05b83__05d,0,0);
    VL_IN8(&a__05b84__05d,0,0);
    VL_IN8(&a__05b85__05d,0,0);
    VL_IN8(&a__05b86__05d,0,0);
    VL_IN8(&a__05b87__05d,0,0);
    VL_IN8(&a__05b88__05d,0,0);
    VL_IN8(&a__05b89__05d,0,0);
    VL_IN8(&a__05b90__05d,0,0);
    VL_IN8(&a__05b91__05d,0,0);
    VL_IN8(&a__05b92__05d,0,0);
    VL_IN8(&a__05b93__05d,0,0);
    VL_IN8(&a__05b94__05d,0,0);
    VL_IN8(&a__05b95__05d,0,0);
    VL_IN8(&a__05b96__05d,0,0);
    VL_IN8(&a__05b97__05d,0,0);
    VL_IN8(&a__05b98__05d,0,0);
    VL_IN8(&a__05b99__05d,0,0);
    VL_IN8(&a__05b100__05d,0,0);
    VL_IN8(&a__05b101__05d,0,0);
    VL_IN8(&a__05b102__05d,0,0);
    VL_IN8(&a__05b103__05d,0,0);
    VL_IN8(&a__05b104__05d,0,0);
    VL_IN8(&a__05b105__05d,0,0);
    VL_IN8(&a__05b106__05d,0,0);
    VL_IN8(&a__05b107__05d,0,0);
    VL_IN8(&a__05b108__05d,0,0);
    VL_IN8(&a__05b109__05d,0,0);
    VL_IN8(&a__05b110__05d,0,0);
    VL_IN8(&a__05b111__05d,0,0);
    VL_IN8(&a__05b112__05d,0,0);
    VL_IN8(&a__05b113__05d,0,0);
    VL_IN8(&a__05b114__05d,0,0);
    VL_IN8(&a__05b115__05d,0,0);
    VL_IN8(&a__05b116__05d,0,0);
    VL_IN8(&a__05b117__05d,0,0);
    VL_IN8(&a__05b118__05d,0,0);
    VL_IN8(&a__05b119__05d,0,0);
    VL_IN8(&a__05b120__05d,0,0);
    VL_IN8(&a__05b121__05d,0,0);
    VL_IN8(&a__05b122__05d,0,0);
    VL_IN8(&a__05b123__05d,0,0);
    VL_IN8(&a__05b124__05d,0,0);
    VL_IN8(&a__05b125__05d,0,0);
    VL_IN8(&a__05b126__05d,0,0);
    VL_IN8(&a__05b127__05d,0,0);
    VL_IN8(&b__05b0__05d,0,0);
    VL_IN8(&b__05b1__05d,0,0);
    VL_IN8(&b__05b2__05d,0,0);
    VL_IN8(&b__05b3__05d,0,0);
    VL_IN8(&b__05b4__05d,0,0);
    VL_IN8(&b__05b5__05d,0,0);
    VL_IN8(&b__05b6__05d,0,0);
    VL_IN8(&b__05b7__05d,0,0);
    VL_IN8(&b__05b8__05d,0,0);
    VL_IN8(&b__05b9__05d,0,0);
    VL_IN8(&b__05b10__05d,0,0);
    VL_IN8(&b__05b11__05d,0,0);
    VL_IN8(&b__05b12__05d,0,0);
    VL_IN8(&b__05b13__05d,0,0);
    VL_IN8(&b__05b14__05d,0,0);
    VL_IN8(&b__05b15__05d,0,0);
    VL_IN8(&b__05b16__05d,0,0);
    VL_IN8(&b__05b17__05d,0,0);
    VL_IN8(&b__05b18__05d,0,0);
    VL_IN8(&b__05b19__05d,0,0);
    VL_IN8(&b__05b20__05d,0,0);
    VL_IN8(&b__05b21__05d,0,0);
    VL_IN8(&b__05b22__05d,0,0);
    VL_IN8(&b__05b23__05d,0,0);
    VL_IN8(&b__05b24__05d,0,0);
    VL_IN8(&b__05b25__05d,0,0);
    VL_IN8(&b__05b26__05d,0,0);
    VL_IN8(&b__05b27__05d,0,0);
    VL_IN8(&b__05b28__05d,0,0);
    VL_IN8(&b__05b29__05d,0,0);
    VL_IN8(&b__05b30__05d,0,0);
    VL_IN8(&b__05b31__05d,0,0);
    VL_IN8(&b__05b32__05d,0,0);
    VL_IN8(&b__05b33__05d,0,0);
    VL_IN8(&b__05b34__05d,0,0);
    VL_IN8(&b__05b35__05d,0,0);
    VL_IN8(&b__05b36__05d,0,0);
    VL_IN8(&b__05b37__05d,0,0);
    VL_IN8(&b__05b38__05d,0,0);
    VL_IN8(&b__05b39__05d,0,0);
    VL_IN8(&b__05b40__05d,0,0);
    VL_IN8(&b__05b41__05d,0,0);
    VL_IN8(&b__05b42__05d,0,0);
    VL_IN8(&b__05b43__05d,0,0);
    VL_IN8(&b__05b44__05d,0,0);
    VL_IN8(&b__05b45__05d,0,0);
    VL_IN8(&b__05b46__05d,0,0);
    VL_IN8(&b__05b47__05d,0,0);
    VL_IN8(&b__05b48__05d,0,0);
    VL_IN8(&b__05b49__05d,0,0);
    VL_IN8(&b__05b50__05d,0,0);
    VL_IN8(&b__05b51__05d,0,0);
    VL_IN8(&b__05b52__05d,0,0);
    VL_IN8(&b__05b53__05d,0,0);
    VL_IN8(&b__05b54__05d,0,0);
    VL_IN8(&b__05b55__05d,0,0);
    VL_IN8(&b__05b56__05d,0,0);
    VL_IN8(&b__05b57__05d,0,0);
    VL_IN8(&b__05b58__05d,0,0);
    VL_IN8(&b__05b59__05d,0,0);
    VL_IN8(&b__05b60__05d,0,0);
    VL_IN8(&b__05b61__05d,0,0);
    VL_IN8(&b__05b62__05d,0,0);
    VL_IN8(&b__05b63__05d,0,0);
    VL_IN8(&b__05b64__05d,0,0);
    VL_IN8(&b__05b65__05d,0,0);
    VL_IN8(&b__05b66__05d,0,0);
    VL_IN8(&b__05b67__05d,0,0);
    VL_IN8(&b__05b68__05d,0,0);
    VL_IN8(&b__05b69__05d,0,0);
    VL_IN8(&b__05b70__05d,0,0);
    VL_IN8(&b__05b71__05d,0,0);
    VL_IN8(&b__05b72__05d,0,0);
    VL_IN8(&b__05b73__05d,0,0);
    VL_IN8(&b__05b74__05d,0,0);
    VL_IN8(&b__05b75__05d,0,0);
    VL_IN8(&b__05b76__05d,0,0);
    VL_IN8(&b__05b77__05d,0,0);
    VL_IN8(&b__05b78__05d,0,0);
    VL_IN8(&b__05b79__05d,0,0);
    VL_IN8(&b__05b80__05d,0,0);
    VL_IN8(&b__05b81__05d,0,0);
    VL_IN8(&b__05b82__05d,0,0);
    VL_IN8(&b__05b83__05d,0,0);
    VL_IN8(&b__05b84__05d,0,0);
    VL_IN8(&b__05b85__05d,0,0);
    VL_IN8(&b__05b86__05d,0,0);
    VL_IN8(&b__05b87__05d,0,0);
    VL_IN8(&b__05b88__05d,0,0);
    VL_IN8(&b__05b89__05d,0,0);
    VL_IN8(&b__05b90__05d,0,0);
    VL_IN8(&b__05b91__05d,0,0);
    VL_IN8(&b__05b92__05d,0,0);
    VL_IN8(&b__05b93__05d,0,0);
    VL_IN8(&b__05b94__05d,0,0);
    VL_IN8(&b__05b95__05d,0,0);
    VL_IN8(&b__05b96__05d,0,0);
    VL_IN8(&b__05b97__05d,0,0);
    VL_IN8(&b__05b98__05d,0,0);
    VL_IN8(&b__05b99__05d,0,0);
    VL_IN8(&b__05b100__05d,0,0);
    VL_IN8(&b__05b101__05d,0,0);
    VL_IN8(&b__05b102__05d,0,0);
    VL_IN8(&b__05b103__05d,0,0);
    VL_IN8(&b__05b104__05d,0,0);
    VL_IN8(&b__05b105__05d,0,0);
    VL_IN8(&b__05b106__05d,0,0);
    VL_IN8(&b__05b107__05d,0,0);
    VL_IN8(&b__05b108__05d,0,0);
    VL_IN8(&b__05b109__05d,0,0);
    VL_IN8(&b__05b110__05d,0,0);
    VL_IN8(&b__05b111__05d,0,0);
    VL_IN8(&b__05b112__05d,0,0);
    VL_IN8(&b__05b113__05d,0,0);
    VL_IN8(&b__05b114__05d,0,0);
    VL_IN8(&b__05b115__05d,0,0);
    VL_IN8(&b__05b116__05d,0,0);
    VL_IN8(&b__05b117__05d,0,0);
    VL_IN8(&b__05b118__05d,0,0);
    VL_IN8(&b__05b119__05d,0,0);
    VL_IN8(&b__05b120__05d,0,0);
    VL_IN8(&b__05b121__05d,0,0);
    VL_IN8(&b__05b122__05d,0,0);
    VL_IN8(&b__05b123__05d,0,0);
    VL_IN8(&b__05b124__05d,0,0);
    VL_IN8(&b__05b125__05d,0,0);
    VL_IN8(&b__05b126__05d,0,0);
    VL_IN8(&b__05b127__05d,0,0);
    VL_OUT8(&f__05b0__05d,0,0);
    VL_OUT8(&f__05b1__05d,0,0);
    VL_OUT8(&f__05b2__05d,0,0);
    VL_OUT8(&f__05b3__05d,0,0);
    VL_OUT8(&f__05b4__05d,0,0);
    VL_OUT8(&f__05b5__05d,0,0);
    VL_OUT8(&f__05b6__05d,0,0);
    VL_OUT8(&f__05b7__05d,0,0);
    VL_OUT8(&f__05b8__05d,0,0);
    VL_OUT8(&f__05b9__05d,0,0);
    VL_OUT8(&f__05b10__05d,0,0);
    VL_OUT8(&f__05b11__05d,0,0);
    VL_OUT8(&f__05b12__05d,0,0);
    VL_OUT8(&f__05b13__05d,0,0);
    VL_OUT8(&f__05b14__05d,0,0);
    VL_OUT8(&f__05b15__05d,0,0);
    VL_OUT8(&f__05b16__05d,0,0);
    VL_OUT8(&f__05b17__05d,0,0);
    VL_OUT8(&f__05b18__05d,0,0);
    VL_OUT8(&f__05b19__05d,0,0);
    VL_OUT8(&f__05b20__05d,0,0);
    VL_OUT8(&f__05b21__05d,0,0);
    VL_OUT8(&f__05b22__05d,0,0);
    VL_OUT8(&f__05b23__05d,0,0);
    VL_OUT8(&f__05b24__05d,0,0);
    VL_OUT8(&f__05b25__05d,0,0);
    VL_OUT8(&f__05b26__05d,0,0);
    VL_OUT8(&f__05b27__05d,0,0);
    VL_OUT8(&f__05b28__05d,0,0);
    VL_OUT8(&f__05b29__05d,0,0);
    VL_OUT8(&f__05b30__05d,0,0);
    VL_OUT8(&f__05b31__05d,0,0);
    VL_OUT8(&f__05b32__05d,0,0);
    VL_OUT8(&f__05b33__05d,0,0);
    VL_OUT8(&f__05b34__05d,0,0);
    VL_OUT8(&f__05b35__05d,0,0);
    VL_OUT8(&f__05b36__05d,0,0);
    VL_OUT8(&f__05b37__05d,0,0);
    VL_OUT8(&f__05b38__05d,0,0);
    VL_OUT8(&f__05b39__05d,0,0);
    VL_OUT8(&f__05b40__05d,0,0);
    VL_OUT8(&f__05b41__05d,0,0);
    VL_OUT8(&f__05b42__05d,0,0);
    VL_OUT8(&f__05b43__05d,0,0);
    VL_OUT8(&f__05b44__05d,0,0);
    VL_OUT8(&f__05b45__05d,0,0);
    VL_OUT8(&f__05b46__05d,0,0);
    VL_OUT8(&f__05b47__05d,0,0);
    VL_OUT8(&f__05b48__05d,0,0);
    VL_OUT8(&f__05b49__05d,0,0);
    VL_OUT8(&f__05b50__05d,0,0);
    VL_OUT8(&f__05b51__05d,0,0);
    VL_OUT8(&f__05b52__05d,0,0);
    VL_OUT8(&f__05b53__05d,0,0);
    VL_OUT8(&f__05b54__05d,0,0);
    VL_OUT8(&f__05b55__05d,0,0);
    VL_OUT8(&f__05b56__05d,0,0);
    VL_OUT8(&f__05b57__05d,0,0);
    VL_OUT8(&f__05b58__05d,0,0);
    VL_OUT8(&f__05b59__05d,0,0);
    VL_OUT8(&f__05b60__05d,0,0);
    VL_OUT8(&f__05b61__05d,0,0);
    VL_OUT8(&f__05b62__05d,0,0);
    VL_OUT8(&f__05b63__05d,0,0);
    VL_OUT8(&f__05b64__05d,0,0);
    VL_OUT8(&f__05b65__05d,0,0);
    VL_OUT8(&f__05b66__05d,0,0);
    VL_OUT8(&f__05b67__05d,0,0);
    VL_OUT8(&f__05b68__05d,0,0);
    VL_OUT8(&f__05b69__05d,0,0);
    VL_OUT8(&f__05b70__05d,0,0);
    VL_OUT8(&f__05b71__05d,0,0);
    VL_OUT8(&f__05b72__05d,0,0);
    VL_OUT8(&f__05b73__05d,0,0);
    VL_OUT8(&f__05b74__05d,0,0);
    VL_OUT8(&f__05b75__05d,0,0);
    VL_OUT8(&f__05b76__05d,0,0);
    VL_OUT8(&f__05b77__05d,0,0);
    VL_OUT8(&f__05b78__05d,0,0);
    VL_OUT8(&f__05b79__05d,0,0);
    VL_OUT8(&f__05b80__05d,0,0);
    VL_OUT8(&f__05b81__05d,0,0);
    VL_OUT8(&f__05b82__05d,0,0);
    VL_OUT8(&f__05b83__05d,0,0);
    VL_OUT8(&f__05b84__05d,0,0);
    VL_OUT8(&f__05b85__05d,0,0);
    VL_OUT8(&f__05b86__05d,0,0);
    VL_OUT8(&f__05b87__05d,0,0);
    VL_OUT8(&f__05b88__05d,0,0);
    VL_OUT8(&f__05b89__05d,0,0);
    VL_OUT8(&f__05b90__05d,0,0);
    VL_OUT8(&f__05b91__05d,0,0);
    VL_OUT8(&f__05b92__05d,0,0);
    VL_OUT8(&f__05b93__05d,0,0);
    VL_OUT8(&f__05b94__05d,0,0);
    VL_OUT8(&f__05b95__05d,0,0);
    VL_OUT8(&f__05b96__05d,0,0);
    VL_OUT8(&f__05b97__05d,0,0);
    VL_OUT8(&f__05b98__05d,0,0);
    VL_OUT8(&f__05b99__05d,0,0);
    VL_OUT8(&f__05b100__05d,0,0);
    VL_OUT8(&f__05b101__05d,0,0);
    VL_OUT8(&f__05b102__05d,0,0);
    VL_OUT8(&f__05b103__05d,0,0);
    VL_OUT8(&f__05b104__05d,0,0);
    VL_OUT8(&f__05b105__05d,0,0);
    VL_OUT8(&f__05b106__05d,0,0);
    VL_OUT8(&f__05b107__05d,0,0);
    VL_OUT8(&f__05b108__05d,0,0);
    VL_OUT8(&f__05b109__05d,0,0);
    VL_OUT8(&f__05b110__05d,0,0);
    VL_OUT8(&f__05b111__05d,0,0);
    VL_OUT8(&f__05b112__05d,0,0);
    VL_OUT8(&f__05b113__05d,0,0);
    VL_OUT8(&f__05b114__05d,0,0);
    VL_OUT8(&f__05b115__05d,0,0);
    VL_OUT8(&f__05b116__05d,0,0);
    VL_OUT8(&f__05b117__05d,0,0);
    VL_OUT8(&f__05b118__05d,0,0);
    VL_OUT8(&f__05b119__05d,0,0);
    VL_OUT8(&f__05b120__05d,0,0);
    VL_OUT8(&f__05b121__05d,0,0);
    VL_OUT8(&f__05b122__05d,0,0);
    VL_OUT8(&f__05b123__05d,0,0);
    VL_OUT8(&f__05b124__05d,0,0);
    VL_OUT8(&f__05b125__05d,0,0);
    VL_OUT8(&f__05b126__05d,0,0);
    VL_OUT8(&f__05b127__05d,0,0);
    VL_OUT8(&cOut,0,0);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vadder___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit Vadder(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vadder(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~Vadder();
  private:
    VL_UNCOPYABLE(Vadder);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
    std::unique_ptr<VerilatedTraceConfig> traceConfig() const override final;
};

#endif  // guard
