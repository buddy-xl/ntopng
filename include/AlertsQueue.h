/*
 *
 * (C) 2019 - ntop.org
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 */

#ifndef _ALERTS_QUEUE_H_
#define _ALERTS_QUEUE_H_

class NetworkInterface;

class AlertsQueue {
 private:
  NetworkInterface *iface;

  void pushAlertJson(AlertType atype, json_object *alert);

 public:
  AlertsQueue(NetworkInterface *iface);

  void pushOutsideDhcpRangeAlert(u_int8_t* cli_mac, Mac *sender_mac,
    u_int32_t ip, u_int32_t router_ip, int vlan_id);
  void pushSlowPeriodicActivity(u_long msec_diff, u_long max_duration_ms, const char *activity_path);
  void pushMacIpAssociationChangedAlert(u_int32_t ip, u_int8_t *old_mac, u_int8_t *new_mac);
  void pushBroadcastDomainTooLargeAlert(const u_int8_t *src_mac, const u_int8_t *dst_mac, u_int32_t spa, u_int32_t tpa, int vlan_id);
  void pushRemoteToRemoteAlert(Host *host);
  void pushLoginTrace(const char*user, bool authorized);
  void pushNfqFlushedAlert(int queue_len, int queue_len_pct, int queue_dropped);
};

#endif
