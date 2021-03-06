
#ifndef _AuxBoundaryData_H_
#define _AuxBoundaryData_H_

#include <AMReX_Geometry.H>
#include <AMReX_MultiFab.H>

namespace amrex {
// \cond CODEGEN 
class AuxBoundaryData
{
public:

    AuxBoundaryData ();

    AuxBoundaryData (const BoxArray& grids,
                     int             n_grow,
                     int             n_comp,
                     const Geometry& geom);

    AuxBoundaryData (const AuxBoundaryData& rhs);

    void copyTo (MultiFab& destmf,
                 int       src_comp,
                 int       dst_comp,
                 int       num_comp) const;

    void copyFrom (const MultiFab& srcmf,
                   int             src_comp,
                   int             dst_comp,
                   int             num_comp,
		   int             src_ng = 0);

    size_t size () const
    {
        BL_ASSERT(!m_empty); BL_ASSERT(m_initialized); return m_fabs.size();
    }

    void copy (const AuxBoundaryData& src,
               int                    src_comp,
               int                    dst_comp,
               int                    num_comp);

    void initialize (const BoxArray& grids,
		     int             n_grow,
                     int             n_comp,
                     const Geometry& geom);
    
    const BoxArray& equivBoxArray () const
    {
        BL_ASSERT(!m_empty); BL_ASSERT(m_initialized); return m_fabs.boxArray();
    }

    void setVal (Real r) { BL_ASSERT(m_initialized); if (!m_empty) m_fabs.setVal(r); }

    const DistributionMapping& DistributionMap () const
    {
        BL_ASSERT(!m_empty); BL_ASSERT(m_initialized); return m_fabs.DistributionMap();
    }

    FArrayBox&       operator[] (const MFIter& mfi)
    {
        BL_ASSERT(!m_empty); BL_ASSERT(m_initialized); return m_fabs[mfi];
    }
    const FArrayBox& operator[] (const MFIter& mfi) const
    {
        BL_ASSERT(!m_empty); BL_ASSERT(m_initialized); return m_fabs[mfi];
    }
    int nGrow () const { BL_ASSERT(m_initialized); return m_ngrow; }

    int nComp () const
    {
        BL_ASSERT(!m_empty); BL_ASSERT(m_initialized); return m_fabs.nComp();
    }

    bool isEmpty () const { return m_empty; }

private:

    MultiFab m_fabs;
    int      m_ngrow;
    bool     m_empty;
    bool     m_initialized;
    //
    // Not defined -- but could be if it's needed.
    // 
    AuxBoundaryData& operator= (const AuxBoundaryData& rhs);
};
// \endcond

}

#endif
