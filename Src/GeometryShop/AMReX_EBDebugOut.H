/*
 *       {_       {__       {__{_______              {__      {__
 *      {_ __     {_ {__   {___{__    {__             {__   {__  
 *     {_  {__    {__ {__ { {__{__    {__     {__      {__ {__   
 *    {__   {__   {__  {__  {__{_ {__       {_   {__     {__     
 *   {______ {__  {__   {_  {__{__  {__    {_____ {__  {__ {__   
 *  {__       {__ {__       {__{__    {__  {_         {__   {__  
 * {__         {__{__       {__{__      {__  {____   {__      {__
 *
 */

#ifndef _EBDebugOut_H_
#define _EBDebugOut_H_

#include "AMReX_Box.H"
#include "AMReX_IntVectSet.H"
#include "AMReX_FArrayBox.H"
#include "AMReX_EBFaceFAB.H"
#include "AMReX_EBCellFAB.H"
#include "AMReX_BaseIVFAB.H"
#include "AMReX_BoxIterator.H"


///bunch of functions to call from the debugger
namespace amrex
{

  ///
  void dumpFAB(const FArrayBox* a_fabPtr);

  ///
  void dumpDBL(const BoxArray* a_fabPtr);

  ///
  void dumpBFR(const BaseFab<Real>* a_fabPtr);

  ///
  void dumpBFI(const BaseFab<int>* a_fabPtr);

  ///
  /**
     Dump inputs to standard out.  For use inside debuggers.
   */
  void dumpBA(const BoxArray* a_dblInPtr);

  ///
  /**
     Dump inputs to standard out.  For use inside debuggers.
   */
  void dumpIVS(const IntVectSet* a_ivsPtr);

  ///
  /**
     Dump inputs to standard out.  For use inside debuggers.
   */
  void dumpBox(const Box* a_boxPtr);

  ///
  /**
     Dump inputs to standard out.  For use inside debuggers.
   */
  void dumpEBFAB(const EBCellFAB* a_fab);

  ///
  /**
     Dump inputs to standard out.  For use inside debuggers.
   */
  void dumpIVFAB(const BaseIVFAB<Real>* a_stenPtr);

  ///
  void dumpEBFace(const EBFaceFAB* a_fab);

  /// 
  void dumpVVoFs(const vector<VolIndex>* vvofs);

  /// 
  void dumpVFaces(const vector<FaceIndex>* vvofs);

}
#endif
