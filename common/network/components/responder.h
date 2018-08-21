/*
 * Copyright (c) 2018 IOTA Stiftung
 * https://github.com/iotaledger/entangled
 *
 * Refer to the LICENSE file for licensing information
 */

#ifndef __COMMON_NETWORK_COMPONENTS_RESPONDER_H__
#define __COMMON_NETWORK_COMPONENTS_RESPONDER_H__

#include <stdbool.h>

#include "utils/handles/thread.h"

// Forward declarations
typedef struct concurrent_queue_transaction_request_t_s responder_queue_t;
typedef struct neighbor_s neighbor_t;
typedef struct _trit_array *trit_array_p;
typedef struct node_s node_t;

typedef struct responder_state_s {
  thread_handle_t thread;
  bool running;
  responder_queue_t *queue;
  node_t *node;
} responder_state_t;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Initializes a responder
 *
 * @param state The responder state
 * @param node A node
 *
 * @return a status code
 */
bool responder_init(responder_state_t *const state, node_t *const node);

/**
 * Starts a responder
 *
 * @param state The responder state
 *
 * @return a status code
 */
bool responder_start(responder_state_t *const state);

/**
 * Adds a request to a responder
 *
 * @param state The responder state
 * @param neighbor Requesting neighbor
 * @param hash Requested hash
 *
 * @return a status code
 */
bool responder_on_next(responder_state_t *const state,
                       neighbor_t *const neighbor, trit_array_p const hash);

/**
 * Stops a responder
 *
 * @param state The responder state
 *
 * @return a status code
 */
bool responder_stop(responder_state_t *const state);

/**
 * Destroys a responder
 *
 * @param state The responder state
 *
 * @return a status code
 */
bool responder_destroy(responder_state_t *const state);

#ifdef __cplusplus
}
#endif

#endif  //__COMMON_NETWORK_COMPONENTS_RESPONDER_H__
