/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.4
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.wrapper.core.jni;

public class OfferDataNym extends Displayable {
  private long swigCPtr;

  public OfferDataNym(long cPtr, boolean cMemoryOwn) {
    super(otapiJNI.OfferDataNym_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  public static long getCPtr(OfferDataNym obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        otapiJNI.delete_OfferDataNym(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }
/*@SWIG:OTAPI.i,379,OT_CAN_BE_CONTAINED_BY@*/
	// Ensure that the GC doesn't collect any OT_CONTAINER instance set from Java
	private OfferListNym containerRefOfferListNym;
	// ----------------	
	protected void addReference(OfferListNym theContainer) {  // This is Java code
		containerRefOfferListNym = theContainer;
	}
	// ----------------
/*@SWIG@*/
	// ------------------------
  public void setGui_label(String value) {
    otapiJNI.OfferDataNym_gui_label_set(swigCPtr, this, value);
  }

  public String getGui_label() {
    return otapiJNI.OfferDataNym_gui_label_get(swigCPtr, this);
  }

  public void setValid_from(String value) {
    otapiJNI.OfferDataNym_valid_from_set(swigCPtr, this, value);
  }

  public String getValid_from() {
    return otapiJNI.OfferDataNym_valid_from_get(swigCPtr, this);
  }

  public void setValid_to(String value) {
    otapiJNI.OfferDataNym_valid_to_set(swigCPtr, this, value);
  }

  public String getValid_to() {
    return otapiJNI.OfferDataNym_valid_to_get(swigCPtr, this);
  }

  public void setServer_id(String value) {
    otapiJNI.OfferDataNym_server_id_set(swigCPtr, this, value);
  }

  public String getServer_id() {
    return otapiJNI.OfferDataNym_server_id_get(swigCPtr, this);
  }

  public void setAsset_type_id(String value) {
    otapiJNI.OfferDataNym_asset_type_id_set(swigCPtr, this, value);
  }

  public String getAsset_type_id() {
    return otapiJNI.OfferDataNym_asset_type_id_get(swigCPtr, this);
  }

  public void setAsset_acct_id(String value) {
    otapiJNI.OfferDataNym_asset_acct_id_set(swigCPtr, this, value);
  }

  public String getAsset_acct_id() {
    return otapiJNI.OfferDataNym_asset_acct_id_get(swigCPtr, this);
  }

  public void setCurrency_type_id(String value) {
    otapiJNI.OfferDataNym_currency_type_id_set(swigCPtr, this, value);
  }

  public String getCurrency_type_id() {
    return otapiJNI.OfferDataNym_currency_type_id_get(swigCPtr, this);
  }

  public void setCurrency_acct_id(String value) {
    otapiJNI.OfferDataNym_currency_acct_id_set(swigCPtr, this, value);
  }

  public String getCurrency_acct_id() {
    return otapiJNI.OfferDataNym_currency_acct_id_get(swigCPtr, this);
  }

  public void setSelling(boolean value) {
    otapiJNI.OfferDataNym_selling_set(swigCPtr, this, value);
  }

  public boolean getSelling() {
    return otapiJNI.OfferDataNym_selling_get(swigCPtr, this);
  }

  public void setScale(String value) {
    otapiJNI.OfferDataNym_scale_set(swigCPtr, this, value);
  }

  public String getScale() {
    return otapiJNI.OfferDataNym_scale_get(swigCPtr, this);
  }

  public void setPrice_per_scale(String value) {
    otapiJNI.OfferDataNym_price_per_scale_set(swigCPtr, this, value);
  }

  public String getPrice_per_scale() {
    return otapiJNI.OfferDataNym_price_per_scale_get(swigCPtr, this);
  }

  public void setTransaction_id(String value) {
    otapiJNI.OfferDataNym_transaction_id_set(swigCPtr, this, value);
  }

  public String getTransaction_id() {
    return otapiJNI.OfferDataNym_transaction_id_get(swigCPtr, this);
  }

  public void setTotal_assets(String value) {
    otapiJNI.OfferDataNym_total_assets_set(swigCPtr, this, value);
  }

  public String getTotal_assets() {
    return otapiJNI.OfferDataNym_total_assets_get(swigCPtr, this);
  }

  public void setFinished_so_far(String value) {
    otapiJNI.OfferDataNym_finished_so_far_set(swigCPtr, this, value);
  }

  public String getFinished_so_far() {
    return otapiJNI.OfferDataNym_finished_so_far_get(swigCPtr, this);
  }

  public void setMinimum_increment(String value) {
    otapiJNI.OfferDataNym_minimum_increment_set(swigCPtr, this, value);
  }

  public String getMinimum_increment() {
    return otapiJNI.OfferDataNym_minimum_increment_get(swigCPtr, this);
  }

  public void setStop_sign(String value) {
    otapiJNI.OfferDataNym_stop_sign_set(swigCPtr, this, value);
  }

  public String getStop_sign() {
    return otapiJNI.OfferDataNym_stop_sign_get(swigCPtr, this);
  }

  public void setStop_price(String value) {
    otapiJNI.OfferDataNym_stop_price_set(swigCPtr, this, value);
  }

  public String getStop_price() {
    return otapiJNI.OfferDataNym_stop_price_get(swigCPtr, this);
  }

  public static OfferDataNym ot_dynamic_cast(Storable pObject) {
    long cPtr = otapiJNI.OfferDataNym_ot_dynamic_cast(Storable.getCPtr(pObject), pObject);
    return (cPtr == 0) ? null : new OfferDataNym(cPtr, false);
  }

}
