// Copyright (c) 2022 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by the QUICHE Copybara export script.

#ifdef QUIC_FLAG

QUIC_FLAG(quic_restart_flag_quic_offload_pacing_to_usps2, false)
// A testonly reloadable flag that will always default to false.
QUIC_FLAG(quic_reloadable_flag_quic_testonly_default_false, false)
// A testonly reloadable flag that will always default to true.
QUIC_FLAG(quic_reloadable_flag_quic_testonly_default_true, true)
// A testonly restart flag that will always default to false.
QUIC_FLAG(quic_restart_flag_quic_testonly_default_false, false)
// A testonly restart flag that will always default to true.
QUIC_FLAG(quic_restart_flag_quic_testonly_default_true, true)
// If trrue, early return before write control frame in OnCanWrite() if the connection is already closed.
QUIC_FLAG(quic_reloadable_flag_quic_no_write_control_frame_upon_connection_close, true)
// If true, QUIC will default enable MTU discovery at server, with a target of 1450 bytes.
QUIC_FLAG(quic_reloadable_flag_quic_enable_mtu_discovery_at_server, false)
// If true, QuicCryptoServerConfig::ParseConfigProtobuf will treat an empty SCID as the same as non-existent.
QUIC_FLAG(quic_restart_flag_quic_return_error_on_empty_scid, true)
// If true, QuicGsoBatchWriter will support release time if it is available and the process has the permission to do so.
QUIC_FLAG(quic_restart_flag_quic_support_release_time_for_gso, false)
// If true, ack frequency frame can be sent from server to client.
QUIC_FLAG(quic_reloadable_flag_quic_can_send_ack_frequency, true)
// If true, allow client to enable BBRv2 on server via connection option \'B2ON\'.
QUIC_FLAG(quic_reloadable_flag_quic_allow_client_enabled_bbr_v2, true)
// If true, an endpoint does not detect path degrading or blackholing until handshake gets confirmed.
QUIC_FLAG(quic_reloadable_flag_quic_no_path_degrading_before_handshake_confirmed, true)
// If true, combine two WriteOrBufferData to one while writing headers.
QUIC_FLAG(quic_reloadable_flag_quic_one_write_for_headers, true)
// If true, default-enable 5RTO blachole detection.
QUIC_FLAG(quic_reloadable_flag_quic_default_enable_5rto_blackhole_detection2, true)
// If true, delay setting of stateless reset token until session initialization.
QUIC_FLAG(quic_reloadable_flag_quic_delay_setting_stateless_reset_token, true)
// If true, disable QUIC version Q043.
QUIC_FLAG(quic_reloadable_flag_quic_disable_version_q043, false)
// If true, disable QUIC version Q046.
QUIC_FLAG(quic_reloadable_flag_quic_disable_version_q046, false)
// If true, disable QUIC version Q050.
QUIC_FLAG(quic_reloadable_flag_quic_disable_version_q050, false)
// If true, disable QUIC version h3 (RFCv1).
QUIC_FLAG(quic_reloadable_flag_quic_disable_version_rfcv1, false)
// If true, disable QUIC version h3-29.
QUIC_FLAG(quic_reloadable_flag_quic_disable_version_draft_29, false)
// If true, disable blackhole detection on server side.
QUIC_FLAG(quic_reloadable_flag_quic_disable_server_blackhole_detection, false)
// If true, disable resumption when receiving NRES connection option.
QUIC_FLAG(quic_reloadable_flag_quic_enable_disable_resumption, true)
// If true, discard INITIAL packet if the key has been dropped.
QUIC_FLAG(quic_reloadable_flag_quic_discard_initial_packet_with_key_dropped, true)
// If true, do not PTO new stream data before handshake confirmed.
QUIC_FLAG(quic_reloadable_flag_quic_donot_pto_stream_data_before_handshake_confirmed, true)
// If true, do not issue a new connection ID that has been claimed by another connection.
QUIC_FLAG(quic_reloadable_flag_quic_check_cid_collision_when_issue_new_cid, true)
// If true, enable server retransmittable on wire PING.
QUIC_FLAG(quic_reloadable_flag_quic_enable_server_on_wire_ping, true)
// If true, flush pending frames as well as pending padding bytes on connection migration.
QUIC_FLAG(quic_reloadable_flag_quic_flush_pending_frames_and_padding_bytes_on_migration, true)
// If true, ietf connection migration is no longer conditioned on connection option RVCM.
QUIC_FLAG(quic_reloadable_flag_quic_remove_connection_migration_connection_option_v2, false)
// If true, include stream information in idle timeout connection close detail.
QUIC_FLAG(quic_reloadable_flag_quic_add_stream_info_to_idle_close_detail, true)
// If true, quic server will send ENABLE_CONNECT_PROTOCOL setting and and endpoint will validate required request/response headers and extended CONNECT mechanism and update code counts of valid/invalid headers.
QUIC_FLAG(quic_reloadable_flag_quic_verify_request_headers_2, true)
// If true, reject or send error response code upon receiving invalid request or response headers. This flag depends on --gfe2_reloadable_flag_quic_verify_request_headers_2.
QUIC_FLAG(quic_reloadable_flag_quic_act_upon_invalid_header, false)
// If true, require handshake confirmation for QUIC connections, functionally disabling 0-rtt handshakes.
QUIC_FLAG(quic_reloadable_flag_quic_require_handshake_confirmation, false)
// If true, server proactively retires client issued connection ID on reverse path validation failure. 
QUIC_FLAG(quic_reloadable_flag_quic_retire_cid_on_reverse_path_validation_failure, true)
// If true, server sends bandwidth eastimate when network is idle for a while.
QUIC_FLAG(quic_restart_flag_quic_enable_sending_bandwidth_estimate_when_network_idle_v2, true)
// If true, set burst token to 2 in cwnd bootstrapping experiment.
QUIC_FLAG(quic_reloadable_flag_quic_conservative_bursts, false)
// If true, use BBRv2 as the default congestion controller. Takes precedence over --quic_default_to_bbr.
QUIC_FLAG(quic_reloadable_flag_quic_default_to_bbr_v2, false)
// If true, use new connection ID in connection migration.
QUIC_FLAG(quic_reloadable_flag_quic_connection_migration_use_new_cid_v2, true)
// If true, use next_connection_id_sequence_number to validate retired cid number.
QUIC_FLAG(quic_reloadable_flag_quic_check_retire_cid_with_next_cid_sequence_number, true)
// If true, use quiche/common/structured_headers in QuicReceiveControlStream::OnPriorityUpdateFrame().
QUIC_FLAG(quic_reloadable_flag_quic_priority_update_structured_headers_parser, true)
// If true, uses conservative cwnd gain and pacing gain when cwnd gets bootstrapped.
QUIC_FLAG(quic_reloadable_flag_quic_conservative_cwnd_and_pacing_gains, false)
// When true, defaults to BBR congestion control instead of Cubic.
QUIC_FLAG(quic_reloadable_flag_quic_default_to_bbr, false)
// When true, support draft-ietf-quic-v2-01
QUIC_FLAG(quic_reloadable_flag_quic_enable_version_2_draft_01, false)
// When true, the BB2U copt causes BBR2 to wait two rounds with out draining the queue before exiting PROBE_UP and BB2S has the same effect in STARTUP.
QUIC_FLAG(quic_reloadable_flag_quic_bbr2_probe_two_rounds, true)
// When true, the BBHI copt causes QUIC BBRv2 to use a simpler algorithm for raising inflight_hi in PROBE_UP.
QUIC_FLAG(quic_reloadable_flag_quic_bbr2_simplify_inflight_hi, true)
// When true, the BBR4 copt sets the extra_acked window to 20 RTTs and BBR5 sets it to 40 RTTs.
QUIC_FLAG(quic_reloadable_flag_quic_bbr2_extra_acked_window, true)

#endif

