/*
 * TcxWriter.h
 *
 *  Created on: Nov 13, 2014
 *      Author: hornja
 */

#ifndef TCXWRITER_H_
#define TCXWRITER_H_

#include "../gpsdata/Activity.h"

class TcxWriter {
public:
    TcxWriter();
    virtual ~TcxWriter();

    void save(const Activity &inputActivity,const QString& tmpFile);

};

#endif /* TCXWRITER_H_ */
