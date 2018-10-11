#include <eosiolib/asset.hpp>
#include <eosiolib/eosio.hpp>
#include <eosiolib/singleton.hpp>
#include <eosiolib/time.hpp>
#include <eosiolib/types.hpp>
#include <iostream>

using namespace eosio;
using namespace std;

class helloworld : public contract
{
  public:
    using contract::contract;
    
    // @abi action
    void hello();
};

EOSIO_ABI(helloworld, (hello));