#include <FabArray.H>

FabArrayBase::FabArrayBase ()
{}

FabArrayBase::FabArrayBase (const BoxArray& bxs, int nvar, int ngrow)
    :
    boxarray(bxs),
    distributionMap(boxarray, ParallelDescriptor::NProcsCFD()),
    n_grow(ngrow),
    n_comp(nvar)
{}

FabArrayBase::FabArrayBase (const BoxArray&            bxs,
                            int                        nvar,
                            int                        ngrow,
                            const DistributionMapping& map)
    :
    boxarray(bxs),
    distributionMap(map),
    n_grow(ngrow),
    n_comp(nvar)
{}

FabArrayBase::~FabArrayBase ()
{}

Box
FabArrayBase::fabbox (int K) const
{
    //
    // Do not use fabparray[K] because it may not be valid in parallel.
    //
    return BoxLib::grow(boxarray[K], n_grow);
}

const Box&
MFIter::validbox () const
{
    return fabArray.box(currentIndex);
}

Box
MFIter::fabbox () const
{
    return fabArray.fabbox(currentIndex);
}

FillBoxId::FillBoxId ()
    :
    m_fillBoxId(-1),
    m_fabIndex(-1)
{}

FillBoxId::FillBoxId (int        newid,
		      const Box& fillbox)
    :
    m_fillBox(fillbox),
    m_fillBoxId(newid),
    m_fabIndex(-1)
{}

//
// Used to cache some CommData stuff in CollectData().
//

CommDataCache::CommDataCache ()
    :
    m_valid(false)
{}

void
CommDataCache::operator= (const Array<CommData>& rhs)
{
    m_commdata = rhs;
    m_valid    = true;
}

bool
CommDataCache::isValid () const
{
    return m_valid;
}

const Array<CommData>&
CommDataCache::theCommData () const
{
    return m_commdata;
}

FabArrayId::FabArrayId  (int newid)
    :
    fabArrayId(newid)
{}

bool
FabArrayId::operator== (const FabArrayId& rhs) const
{
    return fabArrayId == rhs.fabArrayId;
}
