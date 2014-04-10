/*
 * qif-objects.h -- QIF objects for the QIF importer
 *
 * Written By:	Derek Atkins <derek@ihtfp.com>
 *
 */

#ifndef QIF_OBJECTS_H
#define QIF_OBJECTS_H

typedef struct _QifObject *QifObject;
typedef struct _QifData *QifData;

struct _QifObject {
  const char*	type;
  void		(*destroy)(QifObject);

  /* QIF Objects contain data beyond this point.. */
};

#define QIF_O_ACCOUNT	"qif-acct"
typedef struct _QifAccount *QifAccount;

#define QIF_O_CATEGORY	"qif-cat"
typedef struct _QifCategory *QifCategory;

#define QIF_O_CLASS	"qif-class"
typedef struct _QifClass *QifClass;

#define QIF_O_SECURITY	"qif-security"
typedef struct _QifSecurity *QifSecurity;

#define QIF_O_TXN	"qif-txn"
typedef struct _QifTxn *QifTxn;
typedef struct _QifSplit *QifSplit;
typedef struct _QifInvstTxn *QifInvstTxn;

void qif_object_init(void);

QifAccount find_or_make_acct(QifContext ctx, char *name, GList *types);
QifCategory find_or_make_cat(QifContext ctx, char *name);
QifClass find_or_make_class(QifContext ctx, char *name);

/* merge the object into the context.  Returns the object that's in
 * the context, which is either the supplied object or the
 * already-existing object.
 */
QifAccount qif_account_merge(QifContext ctx, QifAccount acct);
QifCategory qif_cat_merge(QifContext ctx, QifCategory cat);
QifClass qif_class_merge(QifContext ctx, QifClass qclass);
QifSecurity qif_security_merge(QifContext ctx, QifSecurity security);

#endif /* QIF_OBJECTS_H */