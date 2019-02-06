# About
`simple-dfa` is an appilcation that feeds input to a DFA and produces the corresponding output.

# Installation
Download the `simple-dfa` folder, open it in terminal and run `make`.

# Usage
From the `simple-dfa` folder, run
```
./main dfa/[filename].dfa [inputs]
```
The format of `[filename].dfa` should be as follows.

```
number of states
states (one per line)  
the start state  
number of final states  
final states (one per line)  
number of transitions  
transitions (one per line, each line in the form "current-state transition-symbol goal-state output-symbol")
```
For transitions on an empty symbol, an empty word/symbol may simply be denoted `empty` in the `.dfa` file. 

# Info
The `src` folder contains the DFA implementation.

# Sample DFAs
## replace
- `main dfa/replace.dfa argv` replaces each occurrence of `0 1 1` by `1 0 0` in the binary vector `argv`.  
**Complexity:** `O(|argv|)`. 

## add1
- `main dfa/add1.dfa n` for a reversed binary vector `n` computes `n+1` in reversed binary.  
**Complexity:** `O(log n)`. 

## sub1
- `main dfa/sub1.dfa n` for a reversed binary vector `n` computes `n-1` in reversed binary.  
**Complexity:** `O(log n)`. 

## mult3
- `main dfa/mult3.dfa n` for a reversed binary vector `n` computes `3*n` in reversed binary.  
**Complexity:** `O(log n)`. 

## mult5
- `main dfa/mult5.dfa n` for a reversed binary vector `n` computes `5*n` in reversed binary.  
**Complexity:** `O(log n)`. 

## collatz
- `main dfa/collatz.dfa n` for a reversed binary vector `n` computes `n%2 ? 3*n+1 : n/2` in reversed binary.  
**Complexity:** `O(log n)`. 

## aba-count
- `main dfa/aba-count.dfa argv` prints `a^n` where `n` is the number of occurrences of `a b a` in `argv`.  
**Complexity:** `O(|argv|)`. 

## add
- `main dfa/add.dfa ab cd ef ...` computes the sum of the reversed binary numbers  `ace...` and `bdf...` in reversed binary.
**Complexity:** `O(|argv|)`. 
