
// licence_cpp

#include "gh-sdi-document.h"

#include "gh/gh-block-base.h"

#include "kans.h"

USING_KANS(SDI)


GH_SDI_Document::GH_SDI_Document()
 :  sdi_infoset_output_(nullptr)
{

}

void GH_SDI_Document::finalize_sentence_boundaries(GH_Block_Base& bl)
{
 QPair<u4, u4> pr = bl.get_effective_start_and_end_indices();
 u4 s = pr.first;
 u4 e = pr.second;
 for(u4 u = s; u <= e; ++u)
 {

 }
}


bool GH_SDI_Document::check_letter(GH_Block_Base& bl, u4 pos)
{
 GH_Block_Base::SDI_Interpretation_Codes sic = bl.get_sdi_interpretation_code_at_index(pos);
 return sic == GH_Block_Base::SDI_Interpretation_Codes::Letter;
}


bool GH_SDI_Document::scan_for_sentence_start(GH_Block_Base& bl, u4 start, u4 end, u4& result)
{
 for(u4 i = start; i <= end; ++i)
 {
  if(check_letter(bl, i))
  {
   result = i;
   return i;
  }
 }
 return false;
}

bool GH_SDI_Document::scan_for_sentence_end(GH_Block_Base& bl, u4 start, u4 end, u4& result)
{
 for(u4 i = start; i <= end; ++i)
 {
  GH_Block_Base::SDI_Interpretation_Codes sic = bl.get_sdi_interpretation_code_at_index(i);
  if(sic == GH_Block_Base::SDI_Interpretation_Codes::Potential_Sentence_End)
  {
   result = i;
   return i;
  }
 }
 return false;
}

