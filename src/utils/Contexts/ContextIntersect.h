/*
 * ContextIntersect.h
 *
 *  Created on: Jan 6, 2014
 *      Author: nek3d
 */

#ifndef CONTEXTINTERSECT_H_
#define CONTEXTINTERSECT_H_

#include "ContextBase.h"

class ContextIntersect : public ContextBase {
public:
	ContextIntersect();
	virtual ~ContextIntersect();
	virtual bool isValidState();

	virtual bool parseCmdArgs(int argc, char **argv, int skipFirstArgs);
	virtual bool determineOutputType();

	//NOTE: Query and database files will only be marked as such by either the
	//parseCmdArgs method, or by explicitly setting them.
	FileRecordMgr *getQueryFile() { return getFile(_queryFileIdx); }
	FileRecordMgr *getDatabaseFile(int idx) { return getFile(_dbFileIdxs[idx]); }
    int getQueryFileIdx() const { return _queryFileIdx; }
	void setQueryFileIdx(int idx) { _queryFileIdx = idx; }
	int getNumDatabaseFiles() { return (int)_dbFileIdxs.size(); }
	const vector<int> &getDbFileIdxs() const { return _dbFileIdxs; }
	const QuickString &getQueryFileName() const { return _files[_queryFileIdx]->getFileName(); }
	const QuickString &getDatabaseFileName(int idx) const { return _files[_dbFileIdxs[idx]]->getFileName(); }
	ContextFileType getQueryFileType() const { return _files[_queryFileIdx]->getFileType(); }
	ContextFileType getDatabaseFileType(int idx) const { return _files[_dbFileIdxs[idx]]->getFileType(); }
	ContextRecordType getQueryRecordType() const { return _files[_queryFileIdx]->getRecordType(); }
	ContextRecordType getDatabaseRecordType(int idx) const { return _files[_dbFileIdxs[idx]]->getRecordType(); }
	int getMaxNumDatabaseFields() const { return _maxNumDatabaseFields; }
	void setMaxNumDatabaseFields(int val) { _maxNumDatabaseFields = val; }
	int getDbIdx(int fileId) { return _fileIdsToDbIdxs.find(fileId)->second; }
	void addDatabaseNameTag(const QuickString &tag) { _dbNameTags.push_back(tag); }
	const QuickString &getDatabaseNameTag(int dbIdx) const { return _dbNameTags[dbIdx]; }

	bool getAnyHit() const {return _anyHit; }
	void setAnyHit(bool val) { _anyHit = val; }

	bool getNoHit() const {return _noHit; }
	void setNoHit(bool val) { _noHit = val; }

	bool getLeftJoin() const {return _leftJoin; }
	void setLeftJoin(bool val) { _leftJoin = val; }

	bool getWriteA() const {return _writeA; }
	void setWriteA(bool val) { _writeA = val; }

	bool getWriteB() const {return _writeB; }
	void setWriteB(bool val) { _writeB = val; }

	bool getWriteCount() const {return _writeCount; }
	void setWriteCount(bool val) { _writeCount = val; }

	bool getWriteOverlap() const {return _writeOverlap; }
	void setWriteOverlap(bool val) { _writeOverlap = val; }

	bool getWriteAllOverlap() const {return _writeAllOverlap; }
	void setWriteAllOverlap(bool val) { _writeAllOverlap = val; }

	bool getHaveFraction() const {return _haveFraction; }
	void setHaveFraction(bool val) { _haveFraction = val; }

	float getOverlapFraction() const { return _overlapFraction; }
	void setOverlapFraction(float fraction) { _overlapFraction = fraction; }

	bool getReciprocal() const {return _reciprocal; }
	void setReciprocal(bool val) { _reciprocal = val; }

	bool getSameStrand() const {return _sameStrand; }
	void setSameStrand(bool val) { _sameStrand = val; }
	bool getForwardOnly() const { return _forwardOnly; }
	bool getReverseOnly() const { return _reverseOnly; }

	bool getDiffStrand() const {return _diffStrand; }
	void setDiffStrand(bool val) { _diffStrand = val; }

    virtual bool hasIntersectMethods() const { return true; }

protected:

	BlockMgr *_splitBlockMgr;

	virtual bool handle_a();
	virtual bool handle_abam();
	virtual bool handle_b();
	virtual bool handle_names();
	virtual bool handle_filenames();

	virtual bool handle_c();
	virtual bool handle_f();
	virtual bool handle_loj();
	virtual bool handle_r();
	virtual bool handle_s();
	virtual bool handle_S();
	virtual bool handle_u();
	virtual bool handle_v();
	virtual bool handle_wa();
	virtual bool handle_wao();
	virtual bool handle_wb();
	virtual bool handle_wo();
};

#endif /* CONTEXTINTERSECT_H_ */
